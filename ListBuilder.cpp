#include "ListBuilder.h"
#include <iterator>
#include <list>
#include <functional>
#include <iostream>

using namespace std;
ListBuilder::ListBuilder(int startyear,int endyear,multimap<string,Grant_rowObject> *somedata){
    
	year_s = startyear;
	year_e = endyear;
	data = somedata;

    // create major list heads
    ListClass *g = new ListClass("Grants", 0, 0.00, true);
    ListClass *cf = new ListClass("Clinical Funding", 0, 0.00, true);
    // create minor list heads
    ListClass *pr_grants = new ListClass("Peer Reviewed", 0, 0.00, true);
    ListClass *i_grants = new ListClass("Industry Sponsored", 0, 0.00, true);
    ListClass *pr_cf = new ListClass("Peer Reviewed", 0, 0.00, true);
    ListClass *i_cf = new ListClass("Industry Sponsored", 0, 0.00, true);
    
    grants = *g;
    peerreviewed_grants = *pr_grants;
    industrygrant_grants = *i_grants;
    
    clinicalfunding = *cf;
    peerreviewed_cf = *pr_cf;
    industrygrant_cf = *i_cf;
    
    grants.addChild(&peerreviewed_grants);  // add child lists to parent lists
    grants.addChild(&industrygrant_grants);
    clinicalfunding.addChild(&peerreviewed_cf);
    clinicalfunding.addChild(&industrygrant_cf);
    
}
// prints a listclass structure 
void ListBuilder::printList(ListClass alist){
    list<ListClass *> * temp = alist.getChildren();
    list<ListClass *>::iterator i = temp->begin();
    while (i != temp->end()){
        printf("Name: %s\n", (*i)->getName().c_str());
        printf("Param1: %d\n", (*i)->getParam1());
        printf("Param2: %0.2d\n", (*i)->getParam2());
        ++ i;
    }
}
// Adds Member to plus/minus list
void ListBuilder::addMember(Member amember){
	
    if (amember.num_pr_g>0){
        if (amember.g_pr_amount>0){
            this->peerreviewed_grants.addChild(new ListClass(amember.grant_pr.getName(), amember.grant_pr.getParam1(), amember.grant_pr.getParam2(), false));
            this->peerreviewed_grants.param2 = this->peerreviewed_grants.param2 + amember.g_pr_amount;
        }
        this->peerreviewed_grants.param1 = this->peerreviewed_grants.param1 + amember.num_pr_g;
    }
    
    if (amember.num_is_g>0){
        if (amember.g_is_amount>0){
            this->industrygrant_grants.addChild(new ListClass(amember.indspr_g.getName(),amember.indspr_g.getParam1(),amember.indspr_g.getParam2(),false));
            this->industrygrant_grants.param2 = this->industrygrant_grants.param2 + amember.g_is_amount;
        }
        this->industrygrant_grants.param1 = this->industrygrant_grants.param1 + amember.num_is_g;
    }
    
    if (amember.num_pr_cf>0){
        if (amember.cf_pr_amount>0){
            this->peerreviewed_cf.addChild(new ListClass(amember.grant_cf.getName(),amember.grant_cf.getParam1(),amember.grant_cf.getParam2(),false));
            this->peerreviewed_cf.param2 = this->peerreviewed_cf.param2 + amember.cf_pr_amount;
        }
        this->peerreviewed_cf.param1 = this->peerreviewed_cf.param1 + amember.num_pr_cf;
    }
    
    if (amember.num_is_cf>0){
        if (amember.cf_is_amount>0){
            this->industrygrant_cf.addChild(new ListClass(amember.indspr_cf.getName(),amember.indspr_cf.getParam1(),amember.indspr_cf.getParam2(),false));
            this->industrygrant_cf.param2 = this->industrygrant_cf.param2 + amember.cf_is_amount;
        }
        this->industrygrant_cf.param1 = this->industrygrant_cf.param1 + amember.num_is_cf;
    }
    this->grants.name = "Grants";
    this->grants.param1 = this->grants.param1 + amember.totalGrants;
    this->grants.param2 = this->grants.param2 + amember.g_pr_amount + amember.g_is_amount;
    this->clinicalfunding.name = "Clinical Funding";
    this->clinicalfunding.param1 = this->clinicalfunding.param1 + amember.totalcf;
    this->clinicalfunding.param2 = this->clinicalfunding.param2 + amember.cf_pr_amount + amember.cf_is_amount;
}
// scans multimap and populates list 
void ListBuilder::scanMap(){
    
   // create a map to keep track of visited row objects
    map<string, bool> visited;

    //std::hash<std::string> str_hash;
    
    unsigned long mapsize;
    mapsize = data->size();
    
    std::multimap<string, Grant_rowObject>::iterator cur = data->begin();
    while (cur != data->end()){

          Member c_mem;
        //unsigned long key = str_hash(current->second.name);
        if ( cur == data->begin()) {
            c_mem = this->tally(cur->second.name);
            this->addMember(c_mem);
            visited.insert(pair<string, bool>(cur->second.name, true));
        }
        else
        {
            map<string, bool>::iterator j = visited.find(cur->second.name);

            if (j == visited.end() || j->first != cur->second.name){
                c_mem = this->tally(cur->second.name);
                this->addMember(c_mem);
                visited.insert(pair<string, bool>(cur->second.name, true));
            }
        }
        ++ cur;
    }

}
// creates the counts for member with the supplied name in the multimap for the plus/minus list entries 
Member ListBuilder::tally(string name){
	
    int numelements = 0;
    numelements =(int) data->count(name);
    std::multimap<string,Grant_rowObject>::iterator iter;
    iter = data->begin();
    
    // debug row count for member name
    // printf("member name row entries %d\n",numelements);
    
    // holds the number of total grants
    int totalgrants = 0;
    int totalcf = 0;
    // holds the number of peer reviewed
    int g_peertotal = 0;
    // holds the number of industry sponsored
    int g_istotal = 0;
    // holds the number of peer reviewed
    int cf_peertotal = 0;
    // holds the number of industry sponsored
    int cf_istotal = 0;
    // holds total amount of funding
    double g_totalamount = 0.00;
    // holds total amount of funding
    double cf_totalamount = 0.00;

    // hold grants peer reviewed funding total
    double g_peeramount = 0.00;
    // hold grants industry sponsor total
    double g_isamount = 0.00;
    // hold clinicsl peerfunding total
    double  cf_peeramount = 0.00;
    // hold clinical industry sponsor total
    double cf_isamount = 0.00;
    // holds completed peer entry grants
    ListClass peerentry_g = ListClass(name,0,0.00, false);;
    // hold completed industry sponsored entry grants
    ListClass isentry_g = ListClass(name,0,0.00, false);
    // holds completed peer entry clinical funding
    ListClass peerentry_cf = ListClass(name,0,0.00, false);;
    // hold completed industry sponsored entry clinical funding
    ListClass isentry_cf = ListClass(name,0,0.00, false);
    // for each item in the table with member name
    for (iter = data->equal_range(name).first; iter!=data->equal_range(name).second;iter++){
        //cout << (*iter).second.sDate << endl;
        if ((this->year_s<=(*iter).second.sDate)&&(this->year_e>=(*iter).second.sDate)){
            // if row is a grant and if row is peer reviewed
            if (((*iter).second.peerReviewed==true) && ((*iter).second.fundType=="Grants")) {
                //cout << "Grant and Peer:" << (*iter).second.name << " " << (*iter).second.fundType << " " << (*iter).second.peerReviewed << " " << (*iter).second.indGrant << endl;
                // update the peertotal
                g_peertotal++;
                // update the running totalamount
                g_totalamount = g_totalamount + (*iter).second.totalAmount;
                // update the running peeramount
                g_peeramount = g_peeramount + (*iter).second.totalAmount;
                // update the peerentry_g
                peerentry_g.param1 = g_peertotal;
                peerentry_g.param2 = g_peeramount;
            }
            if (((*iter).second.peerReviewed==true) && ((*iter).second.fundType=="Clinical Trials")) {
                //cout << "Clinical and Peer:" << (*iter).second.name << " " << (*iter).second.fundType << " " << (*iter).second.peerReviewed << " " << (*iter).second.indGrant << endl;
                // update the peertotal
                cf_peertotal++;
                // update the peer amount
                cf_peeramount = cf_peeramount + (*iter).second.totalAmount;
                // update the running totalamount
                cf_totalamount = cf_totalamount + (*iter).second.totalAmount;
                // update the clinical funding peer entry
                peerentry_cf.param1 = cf_peertotal;
                peerentry_cf.param2 = cf_peeramount;
            }

            // if industry grant and grants
            if (((*iter).second.indGrant==true) && ((*iter).second.fundType=="Grants")) {
                //cout << "Grant and IndSpos:" << (*iter).second.name << " " << (*iter).second.fundType << " " << (*iter).second.peerReviewed << " " << (*iter).second.indGrant << endl;
                g_istotal++;
                g_isamount = g_isamount + (*iter).second.totalAmount;
                g_totalamount = g_totalamount +(*iter).second.totalAmount;
                isentry_g.param1 = g_istotal;
                isentry_g.param2 = g_isamount;
            }
            // if industry grant and clinical trials
            if (((*iter).second.indGrant==true) && ((*iter).second.fundType=="Clinical Trials")) {
                //cout << "Clinic and IndSpons:" << (*iter).second.name << " " << (*iter).second.fundType << " " << (*iter).second.peerReviewed << " " << (*iter).second.indGrant << endl;
                cf_istotal++;
                cf_isamount = cf_isamount + (*iter).second.totalAmount;
                cf_totalamount = cf_totalamount +(*iter).second.totalAmount;
                isentry_cf.param1 = cf_istotal;
                isentry_cf.param2 = cf_isamount;
            }

        }
        
    }
    // total grants = peer reviewed total + industry sponsored total
    totalgrants = g_peertotal + g_istotal;
    totalcf = cf_peertotal + cf_istotal;
    
    // pack result into member structure
    Member result;
    
    result.grant_pr = peerentry_g;
    result.grant_cf = peerentry_cf;
    result.indspr_g = isentry_g;
    result.indspr_cf = isentry_cf;
    
    result.totalGrants = totalgrants;
    result.num_pr_g = g_peertotal;
    result.num_is_g = g_istotal;
    result.g_is_amount = g_isamount;
    result.g_pr_amount = g_peeramount;
    
    result.totalcf = totalcf;
    result.num_pr_cf = cf_peertotal;
    result.num_is_cf = cf_istotal;
    result.cf_is_amount = cf_isamount;
    result.cf_pr_amount = cf_peeramount;

    // return the result
    return result;
    
}

