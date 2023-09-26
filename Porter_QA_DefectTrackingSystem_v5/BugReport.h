#pragma once
#include <iostream>
#include <list>
#include <String>
#include <msclr/marshal_cppstd.h>
#include <nlohmann/json.hpp>
#include <fstream>
using namespace std;

//meh, we could change this so we can dynamically alter it within the program, this creates a really rigid structure
public enum Severity { neutral, low, med, high, critical };
public class BugReport
{
public:
	int bugID;
	string bugTitle;
	string bugCategory;
	Severity bugSeverity;
	string bugDescription;
	string bugReporter;
	string bugAssignee;


	//track data
	string dateCreated = "";
	string lastUpdate = "";
	//newer -> may not be FULLY implemented, may have inconsistencies within greater functionality
	bool attachedSnippets = false;
	string codeSnippets;
	string linkedReports;


	//funcs
	BugReport();
	BugReport(string title, string category, string desc, Severity severity, string reporter, string assignTo);
	BugReport(string title, string category, string desc, Severity severity, string reporter, string assignTo, string dateCreated);
	BugReport(int id, string title, string category, string desc, Severity severity, string reporter, string assignTo);
	BugReport(int id, string title, string category, string desc, Severity severity, string reporter, string assignTo, string dateCreated);

	void SetSeverity(int sevc);
	Severity GetSeverity();
};