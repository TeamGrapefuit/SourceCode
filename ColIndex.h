//
//  ColIndex.h
//  Row Builder
//
//  Created by Jason Smash on 2015-10-19.
//  Copyright (c) 2015 Jason Smash. All rights reserved.
//

#ifndef Row_Builder_ColIndex_h
#define Row_Builder_ColIndex_h

struct ColIndex {
    
    //How To Use This Structure
    /*
     <membername>_loc is an integer corresponding the column number in the .CSV file for the <membername>
     
     ColIndex contains a member for all necessary members in ALL TYPES of  csv file (grants, publications, presentations, teaching)
     
     unused members should be unitialized or set to -1
     */
    
    //***Members for Grant
    
    int name_loc; //Member Name
    int domain_loc; //Primary Domain
    int fundType_loc;//Funding Type (Grants or Clinical Trials)
    int stat_loc; //Status
    int role_loc; //research role
    int title_loc; //Research Title
    int pInvestigator_loc; //Primary Investigator
    int cpInvestigator_loc; //co Investogator
    int peerReviewed_loc; //Is peer reviewed
    int indGrant_loc; //Is an industry  grant
    int sDate_loc; //Start Date
    int eDate_loc; // end date
    int totalAmount_loc; // total amount
    
    
    //***Members for PRESENTATIONS
    
    //Already included above
    /*
     int name_loc; //member name
     int domain_loc; //Primary Domain
     int role_loc; //presentation role
     int title_loc; // Presentation Title
     */
    int type_loc; //Presentation Type
    int date_loc; // Presentation Date
    
    //***Members for PUBLICATIONS
    
    //Already Included Above
    /*
     int name_loc; //memberName
     int domain_loc; //primary Domain
     int role_loc; //Journal Role
     int title_loc; //Journal Title
     int type_loc; //Journal Type
     */
    
    int pubStatus_loc; // Publication Status
    int author_loc;// Journal Author
    int jName_loc; //Journal Name
    int statDate_loc; //Status Date
    
    //***Members for TEACHING
    
    //Already Included Above
    /*
     int name_loc; //Member Name
     int domain_loc; // Primary domain
     int sDate_loc;// Start Date
     int eDate_loc; // End Date
     */
    int program_loc; //Program
    int courseType_loc; //Course Type
    int geoScope_loc; //
    int nTeach_loc; // Number of teaching sessions
    int hpTeach_loc;//hours per teaching session or week
    int tHours_loc;//total hours
    
    
    
    
};

#endif
