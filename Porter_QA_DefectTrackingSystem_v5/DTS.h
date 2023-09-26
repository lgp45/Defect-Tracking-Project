#pragma once#include <iostream>
#include <vector>
#include <string>

#include "BugReport.h"
using namespace std;
using json = nlohmann::json;
public class DTS
{
public:

	vector<BugReport> bugReports;
	//BASE JSON CRUD
	void CreateJsonObject(vector<BugReport> bugReports);
	//void CreateAndSaveJsonObject(const list<BugReport>& bugReports);
	void CreateAndSaveJsonObject();

	void SaveJsonObject(const json& bug);
	void ReadJsonObject(const json& j);
	void OpenJsonFile();
	void GrabReportList();
	int GrabReportCount();
	json GrabJsonFile();
	
	//MIXED CRUD -> LIST -> JSON UPDATER

	//BUG REPORTS
	void CreateBugReport();
	void CreateBugReport(string title, string category, string desc, Severity severity, string reporter, string assignTo);
	void CreateBugReport(string title, string category, string desc, Severity severity, string reporter, string assignTo, string createdOn);
	void CreateBugReport(int id, string title, string category, string desc, Severity severity, string reporter, string assignTo);
	void CreateBugReport(int id, string title, string category, string desc, Severity severity, string reporter, string assignTo, string createdOn);
	void FindAndDeleteBugReport(int bugID);
	void FindAndUpdateBugReporter(int bugID, BugReport updatedReport);

	//logger system
	void ReadLogger();
	void WriteToLog(string msg);


private:
	

};