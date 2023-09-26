#include "DTS.h"

    //JSON CRUD
void DTS::CreateJsonObject(vector<BugReport> bugReports)
{
    /*
    // create a JSON array to store the bug reports
    json j;
    j["BugReport"] = json::array();
    for (const auto& bug : bugReports)
    {
        // create a JSON object for each bug report
        json bugJSON;
        bugJSON["bugID"] = bug.bugID;
        bugJSON["bugTitle"] = bug.bugTitle;
        bugJSON["bugCategory"] = bug.bugCategory;
        bugJSON["bugSeverity"] = bug.bugSeverity;
        bugJSON["bugDescription"] = bug.bugDescription;
        bugJSON["bugReporter"] = bug.bugReporter;
        bugJSON["bugAssignee"] = bug.bugAssignee;

        // add the JSON object to the array
        j["BugReport"].push_back(bugJSON);
        //j.push_back(bugJSON);
    }
    // output the JSON array
    std::cout << j.dump(4) << std::endl;
    */
}
void DTS::CreateAndSaveJsonObject()
{
    json j = GrabJsonFile();

    // Create a JSON array to store all the bug reports
    json bugReportsArray = json::array();

    for (int i = 0; i < bugReports.size(); i++)
    {
        cout << "Bug Report: " << i << endl;
    }

    // Loop through the list of bug reports
    for (const auto& bug : bugReports)
    {
        json bugJSON;
        bugJSON["bugID"] = bug.bugID;
        bugJSON["bugTitle"] = bug.bugTitle;
        bugJSON["bugCategory"] = bug.bugCategory;
        bugJSON["bugSeverity"] = bug.bugSeverity;
        bugJSON["bugDescription"] = bug.bugDescription;
        bugJSON["bugReporter"] = bug.bugReporter;
        bugJSON["bugAssignee"] = bug.bugAssignee;
        bugJSON["dateCreated"] = bug.dateCreated;
        bugJSON["dateUpdated"] = bug.lastUpdate;
        bugReportsArray.push_back(bugJSON);
    }

    // Update the contents of the JSON object
    j["BugReport"] = bugReportsArray;
    // Write the updated JSON object to the file
    ofstream o("bug_reports.json", ios::trunc);
    o << setw(4) << j << endl;
    o.close();
}
void DTS::GrabReportList()
{
    std::ifstream file("bug_reports.json");
    // parse the file contents into a json object
    json j;
    file >> j;
    // close the file
    file.close();

    cout << j.dump(4);
    auto jb = j;
    // access the bug reports array
    auto jBugReports = j["BugReport"];
    // iterate over the bug reports array and add each report to the list
    for (const auto& jBugReport : jBugReports)
    {
        BugReport bugReport;
        bugReport.bugID = jBugReport["bugID"];
        bugReport.bugTitle = jBugReport["bugTitle"];
        bugReport.bugCategory = jBugReport["bugCategory"];
        bugReport.bugSeverity = jBugReport["bugSeverity"];
        bugReport.bugDescription = jBugReport["bugDescription"];
        bugReport.bugReporter = jBugReport["bugReporter"];
        bugReport.bugAssignee = jBugReport["bugAssignee"];
        bugReport.dateCreated = jBugReport["dateCreated"];
        bugReport.lastUpdate = jBugReport["dateUpdated"];
        // add the bug report to the list
        bugReports.push_back(bugReport);
    }
}
int DTS::GrabReportCount()
{
    int count = 0;
    std::ifstream file("bug_reports.json");
    // parse the file contents into a json object
    json j;
    file >> j;
    // close the file
    file.close();

    cout << j.dump(4);
    auto jb = j;
    // access the bug reports array
    auto jBugReports = j["BugReport"];
    // iterate over the bug reports array and add each report to the list
    for (const auto& jBugReport : jBugReports)
    {
        count += 1;
    }
    return count;
}
void DTS::OpenJsonFile()
{
    cout << "Loading in bug report data file...\n";
    // open the file
    std::ifstream file("bug_reports.json");
    // parse the file contents into a json object
    json j;
    file >> j;
    // close the file
    file.close();
    
    cout << j.dump(4);
    auto jb = j;
    // access the bug reports array
    auto jBugReports = j["BugReport"];
    // iterate over the bug reports array and add each report to the list
    for (const auto& jBugReport : jBugReports)
    {
        BugReport bugReport;
        bugReport.bugID = jBugReport["bugID"];
        bugReport.bugTitle = jBugReport["bugTitle"];
        bugReport.bugCategory = jBugReport["bugCategory"];
        bugReport.bugSeverity = jBugReport["bugSeverity"];
        bugReport.bugDescription = jBugReport["bugDescription"];
        bugReport.bugReporter = jBugReport["bugReporter"];
        bugReport.bugAssignee = jBugReport["bugAssignee"];
        bugReport.dateCreated = jBugReport["dateCreated"];
        bugReport.lastUpdate = jBugReport["dateUpdated"];
        // add the bug report to the list
        bugReports.push_back(bugReport);
    }
    for (int i = 0; i < bugReports.size(); i++)
    {
        cout << "Bug Report " << i << endl;
    }
    cout << "Data file has been fully loaded.\n";
}
json DTS::GrabJsonFile()
{
    std::ifstream file("bug_reports.json");
    // parse the file contents into a json object
    json j;
    file >> j;
    // close the file
    file.close();

    cout << j.dump(4);
    auto jb = j;
    // access the bug reports array
    auto jBugReports = j["BugReport"];
    // iterate over the bug reports array and add each report to the list
    for (const auto& jBugReport : jBugReports)
    {
        bool check = false;
        for (int i = 0; i < bugReports.size(); i++)
        {
            if (bugReports[i].bugTitle != jBugReport["bugTitle"])
            {
                check = true;
            }
        }
        
        if (check == true)
        {
            BugReport bugReport;
            bugReport.bugID = jBugReport["bugID"];
            bugReport.bugTitle = jBugReport["bugTitle"];
            bugReport.bugCategory = jBugReport["bugCategory"];
            bugReport.bugSeverity = jBugReport["bugSeverity"];
            bugReport.bugDescription = jBugReport["bugDescription"];
            bugReport.bugReporter = jBugReport["bugReporter"];
            bugReport.bugAssignee = jBugReport["bugAssignee"];
            bugReport.dateCreated = jBugReport["dateCreated"];
            bugReport.lastUpdate = jBugReport["dateUpdated"];
            // add the bug report to the list
            bugReports.push_back(bugReport);
        }


    }
    return j;
}
void DTS::SaveJsonObject(const json &bugs)
{
    cout << "Saving to json file...\n";
    // open a file stream
    ofstream file("bug_reports.json");
    // write the JSON array to the file
    file << bugs << endl;
    // close the file stream
    file.close();
}
void DTS::ReadJsonObject(const json& j)
{
    for (const auto& bugJSON : j)
    {
        // extract values from the JSON object
        int bugID = bugJSON["bugID"];
        string bugTitle = bugJSON["bugTitle"];
        string bugCategory = bugJSON["bugCategory"];
        Severity bugSeverity = bugJSON["bugSeverity"];
        string bugDescription = bugJSON["bugDescription"];
        string bugReporter = bugJSON["bugReporter"];
        string bugAssignee = bugJSON["bugAssignee"];

        // create a BugReport object with the extracted values
        BugReport bug(bugID, bugTitle, bugCategory, bugDescription, bugSeverity, bugReporter, bugAssignee);

        // add the bug report to the list
        bugReports.push_back(bug);
    }
}


//BUG REPORTS AND BUG REPORT CRUD

//BUG REPORTS --Create == INSERT 
void DTS::CreateBugReport()
{
    int id = GrabReportCount() + 1;
    BugReport bug = BugReport();
    bug.bugID = id;
    bugReports.push_back(bug);
}
void DTS::CreateBugReport(string title, string category, string desc, Severity severity, string reporter, string assignTo) 
{
    int id = GrabReportCount() + 1;
	BugReport bug(title, category, desc, severity, reporter, assignTo);
    bug.bugID = id;
	bugReports.push_back(bug);
    std::cout << "Bug Report " << " created.";
}
void DTS::CreateBugReport(string title, string category, string desc, Severity severity, string reporter, string assignTo, string createdOn)
{
    int id = GrabReportCount() + 1;
    BugReport bug(title, category, desc, severity, reporter, assignTo, createdOn);
    bug.bugID = id;
    bugReports.push_back(bug);
    std::cout << "Bug Report " << " created.";
}
void DTS::CreateBugReport(int id, string title, string category, string desc, Severity severity, string reporter, string assignTo)
{
    int mid = GrabReportCount() + 1;
    BugReport bug(id, title, category, desc, severity, reporter, assignTo);
    bug.bugID = mid;
    bugReports.push_back(bug);
    std::cout << "Bug Report " + to_string(id) << " created.";
}
void DTS::CreateBugReport(int id, string title, string category, string desc, Severity severity, string reporter, string assignTo, string createdOn)
{
    int mid = GrabReportCount() + 1;
    BugReport bug(id, title, category, desc, severity, reporter, assignTo, createdOn);
    bug.bugID = mid;
    bugReports.push_back(bug);
    std::cout << "Bug Report " + to_string(id) << " created.";
}

//NEW CRUD TESTING
void DTS::FindAndDeleteBugReport(int bugID)
{
    // open the file
    std::ifstream file("bug_reports.json");
    // parse the file contents into a json object
    json j;
    file >> j;
    // close the file
    file.close();
    
    cout << j.dump(4);
    auto jb = j;
    // access the bug reports array
    auto jBugReports = j["BugReport"];
    // iterate over the bug reports array and add each report to the list
    for (const auto& jBugReport : jBugReports)
    {
        BugReport bugReport;
        bugReport.bugID = jBugReport["bugID"];
        bugReport.bugTitle = jBugReport["bugTitle"];
        bugReport.bugCategory = jBugReport["bugCategory"];
        bugReport.bugSeverity = jBugReport["bugSeverity"];
        bugReport.bugDescription = jBugReport["bugDescription"];
        bugReport.bugReporter = jBugReport["bugReporter"];
        bugReport.bugAssignee = jBugReport["bugAssignee"];
        bugReport.dateCreated = jBugReport["dateCreated"];
        bugReport.lastUpdate = jBugReport["dateUpdated"];
        // add the bug report to the list
        if (bugReport.bugID != bugID)
        {
            bugReports.push_back(bugReport);
        }

    }

    // Create a JSON array to store all the bug reports
    json bugReportsArray = json::array();

    // Loop through the list of bug reports
    for (const auto& bug : bugReports)
    {
        json bugJSON;
        bugJSON["bugID"] = bug.bugID;
        bugJSON["bugTitle"] = bug.bugTitle;
        bugJSON["bugCategory"] = bug.bugCategory;
        bugJSON["bugSeverity"] = bug.bugSeverity;
        bugJSON["bugDescription"] = bug.bugDescription;
        bugJSON["bugReporter"] = bug.bugReporter;
        bugJSON["bugAssignee"] = bug.bugAssignee;
        bugJSON["dateCreated"] = bug.dateCreated;
        bugJSON["dateUpdated"] = bug.lastUpdate;
        bugReportsArray.push_back(bugJSON);
    }

    // Update the contents of the JSON object
    j["BugReport"] = bugReportsArray;
    // Write the updated JSON object to the file
    ofstream o("bug_reports.json", ios::trunc);
    o << setw(4) << j << endl;
    o.close();
}
void DTS::FindAndUpdateBugReporter(int bugID, BugReport updatedReport)
{
    // open the file
    std::ifstream file("bug_reports.json");
    // parse the file contents into a json object
    json j;
    file >> j;
    // close the file
    file.close();

    cout << j.dump(4);


    // Create a JSON array to store all the bug reports
    json bugReportsArray = json::array();

    // Loop through the list of bug reports
    for (const auto& bug : bugReports)
    {
        json bugJSON;
        bugJSON["bugID"] = bug.bugID;
        if (bug.bugID == bugID)
        {
            bugJSON["bugTitle"] = updatedReport.bugTitle;
            bugJSON["bugCategory"] = updatedReport.bugCategory;
            bugJSON["bugSeverity"] = updatedReport.bugSeverity;
            bugJSON["bugDescription"] = updatedReport.bugDescription;
            bugJSON["bugReporter"] = updatedReport.bugReporter;
            bugJSON["bugAssignee"] = updatedReport.bugAssignee;
            bugJSON["dateCreated"] = updatedReport.dateCreated;
            bugJSON["dateUpdated"] = updatedReport.lastUpdate;
        }
        else
        {
            bugJSON["bugTitle"] = bug.bugTitle;
            bugJSON["bugCategory"] = bug.bugCategory;
            bugJSON["bugSeverity"] = bug.bugSeverity;
            bugJSON["bugDescription"] = bug.bugDescription;
            bugJSON["bugReporter"] = bug.bugReporter;
            bugJSON["bugAssignee"] = bug.bugAssignee;
            bugJSON["dateCreated"] = bug.dateCreated;
            bugJSON["dateUpdated"] = bug.lastUpdate;
        }

        bugReportsArray.push_back(bugJSON);
    }

    // Update the contents of the JSON object
    j["BugReport"] = bugReportsArray;
    // Write the updated JSON object to the file
    ofstream o("bug_reports.json", ios::trunc);
    o << setw(4) << j << endl;
    o.close();
}



//APPLICATION BACKEND LOGGER FUNCS;
void DTS::ReadLogger()
{
    std::ifstream file("dts_syslog.txt");
    string fullLog;
    string lines;
    if (file.good())
    {
        while (getline(file, lines)) {
            fullLog += lines + '\n';
        }

        //this could be very long and may be omitted
        cout << fullLog;
    }
    else if(!file.good())
    {
        cout << "ERROR: File could not be opened, found, or a corruption is present.";
        return;
    }

    file.close();
}
void DTS::WriteToLog(string msg)
{
    std::ofstream file("dts_syslog.txt", ios::app);
    file << msg << endl;
    file.close();
}

