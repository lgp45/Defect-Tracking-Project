#include "BugReport.h"

BugReport::BugReport() 
{
	
}
BugReport::BugReport(string title, string category, string desc, Severity severity, string reporter, string assignTo)
{
	bugTitle = title;
	bugCategory = category;
	bugSeverity = severity;
	bugDescription = desc;
	bugReporter = reporter;
	bugAssignee = assignTo;
}

BugReport::BugReport(string title, string category, string desc, Severity severity, string reporter, string assignTo, string createdOn)
{
	bugTitle = title;
	bugCategory = category;
	bugSeverity = severity;
	bugDescription = desc;
	bugReporter = reporter;
	bugAssignee = assignTo;
	dateCreated = createdOn;
}
BugReport::BugReport(int id, string title, string category, string desc, Severity severity, string reporter, string assignTo)
{
	bugID = id;
	bugTitle = title;
	bugCategory = category;
	bugSeverity = severity;
	bugDescription = desc;
	bugReporter = reporter;
	bugAssignee = assignTo;
}
BugReport::BugReport(int id, string title, string category, string desc, Severity severity, string reporter, string assignTo, string createdOn)
{
	bugID = id;
	bugTitle = title;
	bugCategory = category;
	bugSeverity = severity;
	bugDescription = desc;
	bugReporter = reporter;
	bugAssignee = assignTo;
	dateCreated = createdOn;
}
void BugReport::SetSeverity(int sev)
{
	switch (sev)
	{
	case 0:
		bugSeverity = Severity::neutral;
		break;
	case 1:
		bugSeverity = Severity::low;
		break;
	case 2:
		bugSeverity = Severity::med;
		break;
	case 3:
		bugSeverity = Severity::high;
		break;
	case 4:
		bugSeverity = Severity::critical;
		break;
	}
}
Severity BugReport::GetSeverity()
{
	return bugSeverity;
}



