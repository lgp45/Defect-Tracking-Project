#pragma once
#include <iostream>
#include <String>
#include <List>
#include "BugReport.h"
#include "DTS.h"
#include <msclr/marshal_cppstd.h>
#include <array>
#include <shellapi.h>

using json = nlohmann::json;
namespace PorterQADefectTrackingSystemv5 {

	using namespace std;
	using namespace System;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Diagnostics;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::Threading::Tasks;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		int rowIndex;
		//grabbing forms junk from CPP


		//function to update the active bugs list in the Active Panel
		void UpdateActiveReports(DTS sys)
		{
			
			for each (BugReport r in sys.bugReports)
			{
				//conversion of line by line, probably a much cleaner way to do it but w/e
#pragma region String Compile From Report
//String^ compID = msclr::interop::marshal_as <String^>(to_string(r.bugID));
				String^ compTitle = msclr::interop::marshal_as <String^>(r.bugTitle);
				String^ compCat = msclr::interop::marshal_as <String^>(r.bugCategory);

				String^ compSev = msclr::interop::marshal_as <String^>(to_string(r.bugSeverity));
				switch (r.bugSeverity)
				{
				case Severity::neutral:
					compSev += ": neutral";
					break;
				case Severity::low:
					compSev += ": low";
					break;
				case Severity::med:
					compSev += ": medium";
					break;
				case Severity::high:
					compSev += ": high";
					break;
				case Severity::critical:
					compSev += ": critcal";
					break;
				}
				String^ compDesc = msclr::interop::marshal_as<String^>(r.bugDescription);
				String^ compRep = msclr::interop::marshal_as<String^>(r.bugReporter);
				String^ compAsg = msclr::interop::marshal_as<String^>(r.bugAssignee);
				String^ compDateCreated = msclr::interop::marshal_as<String^>(r.dateCreated);
				String^ compDateUpdated = msclr::interop::marshal_as<String^>(r.lastUpdate);
				List<String^>^ set = gcnew List <String^>();
				set->Add(msclr::interop::marshal_as <String^>(to_string(r.bugID)));
				set->Add(compTitle);
				set->Add(compCat);
				set->Add(compSev);
				set->Add(compDesc);
				set->Add(compRep);
				set->Add(compAsg);
				set->Add(compDateCreated);
				set->Add(compDateUpdated);
				bugGrid->Rows->Add(set[0], set[1], set[2], set[3], set[4], set[5], set[6], set[7], set[8]);
#pragma endregion
			}
		}

		MainWindow(void)
		{

			bool set = false;
			//init all components
			InitializeComponent();
			
			//init the defect tracking system
			DTS sys;
			sys.bugReports = vector<BugReport>();
			//Preload the json data file to the window pane
			//sys.CreateJsonObject(sys.bugReports);
			sys.OpenJsonFile();
			//UpdateActiveReports(sys);
			
			//Fill the applications bug report section, this is all of the recorded bug reports held in the JSON data file bug_reports.json
			for each (BugReport r in sys.bugReports)
			{
				//conversion of line by line, probably a much cleaner way to do it but w/e
				#pragma region String Compile From Report
				//String^ compID = msclr::interop::marshal_as <String^>(to_string(r.bugID));
				String^ compTitle = msclr::interop::marshal_as <String^>(r.bugTitle);
				String^ compCat = msclr::interop::marshal_as <String^>(r.bugCategory);
				
				String^ compSev = msclr::interop::marshal_as <String^>(to_string(r.bugSeverity));
				switch (r.bugSeverity)
				{
				case Severity::neutral:
					compSev += ": neutral";
					break;
				case Severity::low:
					compSev += ": low";
					break;
				case Severity::med:
					compSev += ": medium";
					break;
				case Severity::high:
					compSev += ": high";
					break;
				case Severity::critical:
					compSev += ": critcal";
					break;
				}
				String^ compDesc = msclr::interop::marshal_as<String^>(r.bugDescription);
				String^ compRep = msclr::interop::marshal_as<String^>(r.bugReporter);
				String^ compAsg = msclr::interop::marshal_as<String^>(r.bugAssignee);
				String^ compDateCreated = msclr::interop::marshal_as<String^>(r.dateCreated);
				String^ compDateUpdated = msclr::interop::marshal_as<String^>(r.lastUpdate);
				List<String^>^ set = gcnew List <String^>();
				set->Add(msclr::interop::marshal_as <String^>(to_string(r.bugID)));
				set->Add(compTitle);
				set->Add(compCat);
				set->Add(compSev);
				set->Add(compDesc);
				set->Add(compRep);
				set->Add(compAsg);
				set->Add(compDateCreated);
				set->Add(compDateUpdated);
				bugGrid->Rows->Add(set[0], set[1], set[2], set[3], set[4], set[5], set[6], set[7], set[8]);
				#pragma endregion
			}

			cout << "\nSecondary Print Out...\n";
			for (int i = 0; i < sys.bugReports.size(); i++)
			{
				cout << i << sys.bugReports[i].bugTitle;
			}
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Forms Stuff
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TextBox^ reporterBox;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ descBox;

	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ titleBox;

	private: System::Windows::Forms::Label^ bugTitle;
private: System::Windows::Forms::Button^ clearForms;

	private: System::Windows::Forms::ComboBox^ categoryBox;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exportToolStripMenuItem;




	private: System::Windows::Forms::TextBox^ assigneeBox;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ loggerBox;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ToolStripMenuItem^ infoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ madeByLGP2023NEITToolStripMenuItem;
	private: System::Windows::Forms::Button^ CategoryButton;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ComboBox^ severityBox;
	private: System::Windows::Forms::DataGridView^ bugGrid;







private: System::Windows::Forms::Label^ catLabel;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::TextBox^ bugInfoBox;

private: System::Windows::Forms::Label^ activeBug;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::TextBox^ bugSeverityBox;


private: System::Windows::Forms::Label^ sevLabel;
private: System::Windows::Forms::TextBox^ bugCategoryBox;

private: System::Windows::Forms::TextBox^ bugTitleBox;
private: System::Windows::Forms::TextBox^ bugIDBox;

private: System::Windows::Forms::Label^ idLabel;
private: System::Windows::Forms::Button^ output;
private: System::Windows::Forms::TextBox^ bugAssigneeBox;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::TextBox^ bugReporterBox;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Button^ codeSnippets;
private: System::Windows::Forms::Button^ resolveBugReport;
private: System::Windows::Forms::Button^ editBugReport;
private: System::Windows::Forms::Button^ deleteBugReport;







private: System::Windows::Forms::Button^ resetForm;
private: System::Windows::Forms::Button^ saveEditReport;
private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ reportDataToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ loggerDataToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ fileFolderToolStripMenuItem;









private: System::Windows::Forms::TextBox^ updatedBox;
private: System::Windows::Forms::Label^ dateUpdatedLabel;
private: System::Windows::Forms::TextBox^ createdBox;
private: System::Windows::Forms::Label^ dateMadeLabel;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Title;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Category;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Severity;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Info;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Reporter;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ AssignedTo;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dateMade;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dateUpdated;

































#pragma endregion



	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->output = (gcnew System::Windows::Forms::Button());
			this->bugGrid = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->updatedBox = (gcnew System::Windows::Forms::TextBox());
			this->dateUpdatedLabel = (gcnew System::Windows::Forms::Label());
			this->createdBox = (gcnew System::Windows::Forms::TextBox());
			this->dateMadeLabel = (gcnew System::Windows::Forms::Label());
			this->saveEditReport = (gcnew System::Windows::Forms::Button());
			this->codeSnippets = (gcnew System::Windows::Forms::Button());
			this->resolveBugReport = (gcnew System::Windows::Forms::Button());
			this->editBugReport = (gcnew System::Windows::Forms::Button());
			this->deleteBugReport = (gcnew System::Windows::Forms::Button());
			this->bugAssigneeBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->bugReporterBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->bugSeverityBox = (gcnew System::Windows::Forms::TextBox());
			this->sevLabel = (gcnew System::Windows::Forms::Label());
			this->bugCategoryBox = (gcnew System::Windows::Forms::TextBox());
			this->catLabel = (gcnew System::Windows::Forms::Label());
			this->bugTitleBox = (gcnew System::Windows::Forms::TextBox());
			this->bugIDBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->idLabel = (gcnew System::Windows::Forms::Label());
			this->bugInfoBox = (gcnew System::Windows::Forms::TextBox());
			this->activeBug = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->resetForm = (gcnew System::Windows::Forms::Button());
			this->severityBox = (gcnew System::Windows::Forms::ComboBox());
			this->CategoryButton = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->loggerBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->assigneeBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->categoryBox = (gcnew System::Windows::Forms::ComboBox());
			this->reporterBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->descBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->titleBox = (gcnew System::Windows::Forms::TextBox());
			this->bugTitle = (gcnew System::Windows::Forms::Label());
			this->clearForms = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reportDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loggerDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileFolderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->infoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->madeByLGP2023NEITToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Title = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Category = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Severity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Info = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Reporter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AssignedTo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateMade = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateUpdated = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bugGrid))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Bug List";
			this->label1->Click += gcnew System::EventHandler(this, &MainWindow::label1_Click);
			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Controls->Add(this->output);
			this->panel1->Controls->Add(this->bugGrid);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(-1, 184);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(704, 247);
			this->panel1->TabIndex = 2;
			// 
			// output
			// 
			this->output->Location = System::Drawing::Point(617, 10);
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(75, 23);
			this->output->TabIndex = 4;
			this->output->Text = L"Output";
			this->output->UseVisualStyleBackColor = true;
			this->output->Click += gcnew System::EventHandler(this, &MainWindow::output_Click);
			// 
			// bugGrid
			// 
			this->bugGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->bugGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->ID, this->Title,
					this->Category, this->Severity, this->Info, this->Reporter, this->AssignedTo, this->dateMade, this->dateUpdated
			});
			this->bugGrid->Location = System::Drawing::Point(3, 39);
			this->bugGrid->Name = L"bugGrid";
			this->bugGrid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->bugGrid->Size = System::Drawing::Size(698, 205);
			this->bugGrid->TabIndex = 3;
			this->bugGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::bugGrid_CellContentClick);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->ItemSize = System::Drawing::Size(42, 18);
			this->tabControl1->Location = System::Drawing::Point(4, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(716, 462);
			this->tabControl1->TabIndex = 3;
			// 
			// tabPage1
			// 
			this->tabPage1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tabPage1->Controls->Add(this->updatedBox);
			this->tabPage1->Controls->Add(this->dateUpdatedLabel);
			this->tabPage1->Controls->Add(this->createdBox);
			this->tabPage1->Controls->Add(this->dateMadeLabel);
			this->tabPage1->Controls->Add(this->saveEditReport);
			this->tabPage1->Controls->Add(this->codeSnippets);
			this->tabPage1->Controls->Add(this->resolveBugReport);
			this->tabPage1->Controls->Add(this->editBugReport);
			this->tabPage1->Controls->Add(this->deleteBugReport);
			this->tabPage1->Controls->Add(this->bugAssigneeBox);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->bugReporterBox);
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->bugSeverityBox);
			this->tabPage1->Controls->Add(this->sevLabel);
			this->tabPage1->Controls->Add(this->bugCategoryBox);
			this->tabPage1->Controls->Add(this->catLabel);
			this->tabPage1->Controls->Add(this->bugTitleBox);
			this->tabPage1->Controls->Add(this->bugIDBox);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->idLabel);
			this->tabPage1->Controls->Add(this->bugInfoBox);
			this->tabPage1->Controls->Add(this->activeBug);
			this->tabPage1->Controls->Add(this->panel1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(708, 436);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"     Active     ";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// updatedBox
			// 
			this->updatedBox->Location = System::Drawing::Point(489, 32);
			this->updatedBox->Name = L"updatedBox";
			this->updatedBox->ReadOnly = true;
			this->updatedBox->Size = System::Drawing::Size(111, 20);
			this->updatedBox->TabIndex = 26;
			// 
			// dateUpdatedLabel
			// 
			this->dateUpdatedLabel->AutoSize = true;
			this->dateUpdatedLabel->Location = System::Drawing::Point(435, 35);
			this->dateUpdatedLabel->Name = L"dateUpdatedLabel";
			this->dateUpdatedLabel->Size = System::Drawing::Size(51, 13);
			this->dateUpdatedLabel->TabIndex = 25;
			this->dateUpdatedLabel->Text = L"Updated:";
			// 
			// createdBox
			// 
			this->createdBox->Location = System::Drawing::Point(489, 6);
			this->createdBox->Name = L"createdBox";
			this->createdBox->ReadOnly = true;
			this->createdBox->Size = System::Drawing::Size(111, 20);
			this->createdBox->TabIndex = 24;
			// 
			// dateMadeLabel
			// 
			this->dateMadeLabel->AutoSize = true;
			this->dateMadeLabel->Location = System::Drawing::Point(435, 9);
			this->dateMadeLabel->Name = L"dateMadeLabel";
			this->dateMadeLabel->Size = System::Drawing::Size(47, 13);
			this->dateMadeLabel->TabIndex = 23;
			this->dateMadeLabel->Text = L"Created:";
			// 
			// saveEditReport
			// 
			this->saveEditReport->Location = System::Drawing::Point(616, 60);
			this->saveEditReport->Name = L"saveEditReport";
			this->saveEditReport->Size = System::Drawing::Size(75, 23);
			this->saveEditReport->TabIndex = 22;
			this->saveEditReport->Text = L"Save";
			this->saveEditReport->UseVisualStyleBackColor = true;
			this->saveEditReport->Visible = false;
			this->saveEditReport->Click += gcnew System::EventHandler(this, &MainWindow::saveEditReport_Click);
			// 
			// codeSnippets
			// 
			this->codeSnippets->Location = System::Drawing::Point(616, 89);
			this->codeSnippets->Name = L"codeSnippets";
			this->codeSnippets->Size = System::Drawing::Size(75, 20);
			this->codeSnippets->TabIndex = 21;
			this->codeSnippets->Text = L"Attached Snippets";
			this->codeSnippets->UseVisualStyleBackColor = true;
			this->codeSnippets->Visible = false;
			this->codeSnippets->Click += gcnew System::EventHandler(this, &MainWindow::codeSnippets_Click);
			// 
			// resolveBugReport
			// 
			this->resolveBugReport->BackColor = System::Drawing::Color::YellowGreen;
			this->resolveBugReport->Location = System::Drawing::Point(616, 4);
			this->resolveBugReport->Name = L"resolveBugReport";
			this->resolveBugReport->Size = System::Drawing::Size(75, 23);
			this->resolveBugReport->TabIndex = 20;
			this->resolveBugReport->Text = L"Squash";
			this->resolveBugReport->UseVisualStyleBackColor = false;
			this->resolveBugReport->Visible = false;
			// 
			// editBugReport
			// 
			this->editBugReport->Location = System::Drawing::Point(616, 31);
			this->editBugReport->Name = L"editBugReport";
			this->editBugReport->Size = System::Drawing::Size(75, 23);
			this->editBugReport->TabIndex = 19;
			this->editBugReport->Text = L"Edit";
			this->editBugReport->UseVisualStyleBackColor = true;
			this->editBugReport->Click += gcnew System::EventHandler(this, &MainWindow::editBugReport_Click);
			// 
			// deleteBugReport
			// 
			this->deleteBugReport->BackColor = System::Drawing::Color::Tomato;
			this->deleteBugReport->Location = System::Drawing::Point(630, 123);
			this->deleteBugReport->Name = L"deleteBugReport";
			this->deleteBugReport->Size = System::Drawing::Size(52, 19);
			this->deleteBugReport->TabIndex = 18;
			this->deleteBugReport->Text = L"Delete";
			this->deleteBugReport->UseVisualStyleBackColor = false;
			this->deleteBugReport->Click += gcnew System::EventHandler(this, &MainWindow::deleteBugReport_Click);
			// 
			// bugAssigneeBox
			// 
			this->bugAssigneeBox->Location = System::Drawing::Point(489, 84);
			this->bugAssigneeBox->Name = L"bugAssigneeBox";
			this->bugAssigneeBox->ReadOnly = true;
			this->bugAssigneeBox->Size = System::Drawing::Size(111, 20);
			this->bugAssigneeBox->TabIndex = 17;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(435, 87);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(53, 13);
			this->label10->TabIndex = 16;
			this->label10->Text = L"Assignee:";
			// 
			// bugReporterBox
			// 
			this->bugReporterBox->Location = System::Drawing::Point(489, 58);
			this->bugReporterBox->Name = L"bugReporterBox";
			this->bugReporterBox->ReadOnly = true;
			this->bugReporterBox->Size = System::Drawing::Size(111, 20);
			this->bugReporterBox->TabIndex = 15;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(435, 61);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(54, 13);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Reporter: ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(10, 43);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(25, 13);
			this->label9->TabIndex = 13;
			this->label9->Text = L"Info";
			// 
			// bugSeverityBox
			// 
			this->bugSeverityBox->Location = System::Drawing::Point(279, 23);
			this->bugSeverityBox->Name = L"bugSeverityBox";
			this->bugSeverityBox->ReadOnly = true;
			this->bugSeverityBox->Size = System::Drawing::Size(155, 20);
			this->bugSeverityBox->TabIndex = 12;
			// 
			// sevLabel
			// 
			this->sevLabel->AutoSize = true;
			this->sevLabel->Location = System::Drawing::Point(225, 26);
			this->sevLabel->Name = L"sevLabel";
			this->sevLabel->Size = System::Drawing::Size(51, 13);
			this->sevLabel->TabIndex = 11;
			this->sevLabel->Text = L"Severity: ";
			// 
			// bugCategoryBox
			// 
			this->bugCategoryBox->Location = System::Drawing::Point(68, 23);
			this->bugCategoryBox->Name = L"bugCategoryBox";
			this->bugCategoryBox->ReadOnly = true;
			this->bugCategoryBox->Size = System::Drawing::Size(155, 20);
			this->bugCategoryBox->TabIndex = 10;
			// 
			// catLabel
			// 
			this->catLabel->AutoSize = true;
			this->catLabel->Location = System::Drawing::Point(10, 26);
			this->catLabel->Name = L"catLabel";
			this->catLabel->Size = System::Drawing::Size(55, 13);
			this->catLabel->TabIndex = 9;
			this->catLabel->Text = L"Category: ";
			// 
			// bugTitleBox
			// 
			this->bugTitleBox->Location = System::Drawing::Point(176, 1);
			this->bugTitleBox->Name = L"bugTitleBox";
			this->bugTitleBox->ReadOnly = true;
			this->bugTitleBox->Size = System::Drawing::Size(258, 20);
			this->bugTitleBox->TabIndex = 8;
			// 
			// bugIDBox
			// 
			this->bugIDBox->Location = System::Drawing::Point(84, 1);
			this->bugIDBox->Name = L"bugIDBox";
			this->bugIDBox->ReadOnly = true;
			this->bugIDBox->Size = System::Drawing::Size(55, 20);
			this->bugIDBox->TabIndex = 7;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(148, 4);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(33, 13);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Title: ";
			// 
			// idLabel
			// 
			this->idLabel->AutoSize = true;
			this->idLabel->Location = System::Drawing::Point(65, 4);
			this->idLabel->Name = L"idLabel";
			this->idLabel->Size = System::Drawing::Size(24, 13);
			this->idLabel->TabIndex = 5;
			this->idLabel->Text = L"ID: ";
			// 
			// bugInfoBox
			// 
			this->bugInfoBox->Location = System::Drawing::Point(6, 59);
			this->bugInfoBox->Multiline = true;
			this->bugInfoBox->Name = L"bugInfoBox";
			this->bugInfoBox->ReadOnly = true;
			this->bugInfoBox->Size = System::Drawing::Size(428, 119);
			this->bugInfoBox->TabIndex = 4;
			// 
			// activeBug
			// 
			this->activeBug->AutoSize = true;
			this->activeBug->Location = System::Drawing::Point(6, 3);
			this->activeBug->Name = L"activeBug";
			this->activeBug->Size = System::Drawing::Size(59, 13);
			this->activeBug->TabIndex = 3;
			this->activeBug->Text = L"Active Bug";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->resetForm);
			this->tabPage2->Controls->Add(this->severityBox);
			this->tabPage2->Controls->Add(this->CategoryButton);
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->loggerBox);
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->assigneeBox);
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Controls->Add(this->categoryBox);
			this->tabPage2->Controls->Add(this->reporterBox);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Controls->Add(this->descBox);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->titleBox);
			this->tabPage2->Controls->Add(this->bugTitle);
			this->tabPage2->Controls->Add(this->clearForms);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(708, 436);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"     Create     ";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// resetForm
			// 
			this->resetForm->Location = System::Drawing::Point(476, 35);
			this->resetForm->Name = L"resetForm";
			this->resetForm->Size = System::Drawing::Size(75, 23);
			this->resetForm->TabIndex = 20;
			this->resetForm->Text = L"Reset Form";
			this->resetForm->UseVisualStyleBackColor = true;
			this->resetForm->Click += gcnew System::EventHandler(this, &MainWindow::resetForm_Click);
			// 
			// severityBox
			// 
			this->severityBox->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(5) {
				L"neutral", L"low", L"med",
					L"high", L"critical"
			});
			this->severityBox->FormattingEnabled = true;
			this->severityBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"neutral", L"low", L"med", L"high", L"critical" });
			this->severityBox->Location = System::Drawing::Point(83, 69);
			this->severityBox->Name = L"severityBox";
			this->severityBox->Size = System::Drawing::Size(143, 21);
			this->severityBox->TabIndex = 19;
			this->severityBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::severityBox_SelectedIndexChanged);
			// 
			// CategoryButton
			// 
			this->CategoryButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CategoryButton->Location = System::Drawing::Point(232, 45);
			this->CategoryButton->Name = L"CategoryButton";
			this->CategoryButton->Size = System::Drawing::Size(27, 19);
			this->CategoryButton->TabIndex = 18;
			this->CategoryButton->Text = L"+";
			this->CategoryButton->UseVisualStyleBackColor = true;
			this->CategoryButton->Click += gcnew System::EventHandler(this, &MainWindow::categoryButton_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(232, 69);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(27, 19);
			this->button3->TabIndex = 17;
			this->button3->Text = L"+";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainWindow::button3_Click);
			// 
			// loggerBox
			// 
			this->loggerBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::RecentlyUsedList;
			this->loggerBox->Location = System::Drawing::Point(25, 353);
			this->loggerBox->Multiline = true;
			this->loggerBox->Name = L"loggerBox";
			this->loggerBox->Size = System::Drawing::Size(514, 48);
			this->loggerBox->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(23, 337);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(43, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Logger:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(431, 407);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 23);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Submit Report";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainWindow::button2_Click);
			// 
			// assigneeBox
			// 
			this->assigneeBox->Location = System::Drawing::Point(83, 123);
			this->assigneeBox->Name = L"assigneeBox";
			this->assigneeBox->Size = System::Drawing::Size(143, 20);
			this->assigneeBox->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 123);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Assigned To: ";
			this->label6->Click += gcnew System::EventHandler(this, &MainWindow::label6_Click);
			// 
			// categoryBox
			// 
			this->categoryBox->FormattingEnabled = true;
			this->categoryBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"General", L"UI", L"Crash", L"Mechanics" });
			this->categoryBox->Location = System::Drawing::Point(83, 43);
			this->categoryBox->Name = L"categoryBox";
			this->categoryBox->Size = System::Drawing::Size(143, 21);
			this->categoryBox->TabIndex = 11;
			this->categoryBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::categoryBox_SelectedIndexChanged);
			// 
			// reporterBox
			// 
			this->reporterBox->Location = System::Drawing::Point(83, 97);
			this->reporterBox->Name = L"reporterBox";
			this->reporterBox->Size = System::Drawing::Size(143, 20);
			this->reporterBox->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(23, 100);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Reporter: ";
			// 
			// descBox
			// 
			this->descBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::RecentlyUsedList;
			this->descBox->Location = System::Drawing::Point(26, 163);
			this->descBox->Multiline = true;
			this->descBox->Name = L"descBox";
			this->descBox->Size = System::Drawing::Size(513, 171);
			this->descBox->TabIndex = 8;
			this->descBox->Text = L"Error Codes / Types:\r\n\r\nFunctions / Tasks Performed:\r\n\r\nExpected Result:\r\n\r\nActua"
				L"l Result:\r\n\r\nNotes:\r\n\r\n";
			this->descBox->TextChanged += gcnew System::EventHandler(this, &MainWindow::textBox4_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(22, 147);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Bug Description:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(27, 45);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Category";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Severity";
			// 
			// titleBox
			// 
			this->titleBox->Location = System::Drawing::Point(83, 17);
			this->titleBox->Name = L"titleBox";
			this->titleBox->Size = System::Drawing::Size(143, 20);
			this->titleBox->TabIndex = 2;
			// 
			// bugTitle
			// 
			this->bugTitle->AutoSize = true;
			this->bugTitle->Location = System::Drawing::Point(28, 20);
			this->bugTitle->Name = L"bugTitle";
			this->bugTitle->Size = System::Drawing::Size(55, 13);
			this->bugTitle->TabIndex = 1;
			this->bugTitle->Text = L"Bug Title: ";
			// 
			// clearForms
			// 
			this->clearForms->Location = System::Drawing::Point(476, 6);
			this->clearForms->Name = L"clearForms";
			this->clearForms->Size = System::Drawing::Size(75, 23);
			this->clearForms->TabIndex = 0;
			this->clearForms->Text = L"Clear Form";
			this->clearForms->UseVisualStyleBackColor = true;
			this->clearForms->Click += gcnew System::EventHandler(this, &MainWindow::clearForms_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Location = System::Drawing::Point(0, 24);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(721, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuStrip2
			// 
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->saveToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(721, 24);
			this->menuStrip2->TabIndex = 5;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->BackColor = System::Drawing::SystemColors::Info;
			this->saveToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->exportToolStripMenuItem,
					this->openToolStripMenuItem, this->infoToolStripMenuItem
			});
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->saveToolStripMenuItem->Text = L"Options";
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->exportToolStripMenuItem->Text = L"Save";
			this->exportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::exportToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->reportDataToolStripMenuItem,
					this->loggerDataToolStripMenuItem, this->fileFolderToolStripMenuItem
			});
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			// 
			// reportDataToolStripMenuItem
			// 
			this->reportDataToolStripMenuItem->Name = L"reportDataToolStripMenuItem";
			this->reportDataToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->reportDataToolStripMenuItem->Text = L"Report Data";
			this->reportDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::reportDataToolStripMenuItem_Click);
			// 
			// loggerDataToolStripMenuItem
			// 
			this->loggerDataToolStripMenuItem->Name = L"loggerDataToolStripMenuItem";
			this->loggerDataToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->loggerDataToolStripMenuItem->Text = L"Logger Data";
			this->loggerDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::loggerDataToolStripMenuItem_Click);
			// 
			// fileFolderToolStripMenuItem
			// 
			this->fileFolderToolStripMenuItem->Name = L"fileFolderToolStripMenuItem";
			this->fileFolderToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->fileFolderToolStripMenuItem->Text = L"File Folder";
			this->fileFolderToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::fileFolderToolStripMenuItem_Click_1);
			// 
			// infoToolStripMenuItem
			// 
			this->infoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->madeByLGP2023NEITToolStripMenuItem });
			this->infoToolStripMenuItem->Name = L"infoToolStripMenuItem";
			this->infoToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->infoToolStripMenuItem->Text = L"Info";
			// 
			// madeByLGP2023NEITToolStripMenuItem
			// 
			this->madeByLGP2023NEITToolStripMenuItem->Name = L"madeByLGP2023NEITToolStripMenuItem";
			this->madeByLGP2023NEITToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->madeByLGP2023NEITToolStripMenuItem->Text = L"LGP 2023 NEIT";
			// 
			// ID
			// 
			this->ID->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ID->FillWeight = 50.2538F;
			this->ID->HeaderText = L"ID";
			this->ID->MinimumWidth = 3;
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			// 
			// Title
			// 
			this->Title->FillWeight = 106.2183F;
			this->Title->HeaderText = L"Title";
			this->Title->Name = L"Title";
			this->Title->ReadOnly = true;
			this->Title->Width = 75;
			// 
			// Category
			// 
			this->Category->FillWeight = 106.2183F;
			this->Category->HeaderText = L"Category";
			this->Category->Name = L"Category";
			this->Category->ReadOnly = true;
			this->Category->Width = 65;
			// 
			// Severity
			// 
			this->Severity->FillWeight = 106.2183F;
			this->Severity->HeaderText = L"Severity";
			this->Severity->Name = L"Severity";
			this->Severity->ReadOnly = true;
			this->Severity->Width = 55;
			// 
			// Info
			// 
			this->Info->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Info->FillWeight = 106.2183F;
			this->Info->HeaderText = L"Description";
			this->Info->Name = L"Info";
			this->Info->ReadOnly = true;
			// 
			// Reporter
			// 
			this->Reporter->FillWeight = 106.2183F;
			this->Reporter->HeaderText = L"Reporter";
			this->Reporter->Name = L"Reporter";
			this->Reporter->ReadOnly = true;
			this->Reporter->Width = 77;
			// 
			// AssignedTo
			// 
			this->AssignedTo->FillWeight = 106.2183F;
			this->AssignedTo->HeaderText = L"Assigned To";
			this->AssignedTo->Name = L"AssignedTo";
			this->AssignedTo->ReadOnly = true;
			this->AssignedTo->Width = 78;
			// 
			// dateMade
			// 
			this->dateMade->FillWeight = 106.2183F;
			this->dateMade->HeaderText = L"Created On";
			this->dateMade->Name = L"dateMade";
			this->dateMade->Width = 77;
			// 
			// dateUpdated
			// 
			this->dateUpdated->FillWeight = 106.2183F;
			this->dateUpdated->HeaderText = L"Updated";
			this->dateUpdated->Name = L"dateUpdated";
			this->dateUpdated->Width = 78;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(721, 501);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->menuStrip2);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->Text = L"Defect Tracking System ";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bugGrid))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void clearForms_Click(System::Object^ sender, System::EventArgs^ e) {

	titleBox->Text = "";
	categoryBox->Text = "";
	severityBox->Text = "";
	reporterBox->Text = "";
	assigneeBox->Text = "";
	descBox->Text = "";
	loggerBox->Text = "";
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}


	   //Begin custom button sets
private: System::Void categoryButton_Click(System::Object^ sender, System::EventArgs^ e) {
	cout << "Add new Category clicked...\n";
	String^ entry = categoryBox->Text;
	
	if (!categoryBox->Items->Contains(entry))
	{
		categoryBox->Items->Add(entry);
	}
	else
	{
		cout << "Category already exists.";
	}
	
	
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	cout << "Add new Severity Level clicked...\n";
	String^ entry = severityBox->Text;

	if (!severityBox->Items->Contains(entry))
	{
		severityBox->Items->Add(entry);
	}
	else
	{
		cout << "Severity level already exists.";
	}
}
private: System::Void severityBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void bugGrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	// Check if the clicked cell is valid.
	rowIndex = e->RowIndex;
	DTS sys;
	sys.GrabReportList();
	// Check if the row index is valid.
	if (rowIndex >= 0)
	{
		// Get the full row of the clicked cell.
		DataGridViewRow^ row = bugGrid->Rows[rowIndex];

		BugReport report;
		String^ temp = bugGrid->Rows[rowIndex]->Cells[1]->Value->ToString();
		for (int i = 0; i < sys.bugReports.size(); i++)
		{
			String ^repTitle = msclr::interop::marshal_as <String^>(sys.bugReports[i].bugTitle);
			if ( repTitle == temp)
			{
				String^ m_id = msclr::interop::marshal_as <String^>(to_string(sys.bugReports[i].bugID));
				String^ m_title = msclr::interop::marshal_as <String^>(sys.bugReports[i].bugTitle);
				String^ m_cat = msclr::interop::marshal_as <String^>(sys.bugReports[i].bugCategory);
				String^ m_sev = msclr::interop::marshal_as <String^>(to_string(sys.bugReports[i].bugSeverity));
				String^ m_desc = msclr::interop::marshal_as <String^>(sys.bugReports[i].bugDescription);
				String^ m_rep = msclr::interop::marshal_as <String^>(sys.bugReports[i].bugReporter);
				String^ m_asg = msclr::interop::marshal_as <String^>(sys.bugReports[i].bugAssignee);
				String^ m_cDate = msclr::interop::marshal_as <String^>(sys.bugReports[i].dateCreated);
				String^ m_uDate = msclr::interop::marshal_as <String^>(sys.bugReports[i].lastUpdate);
				switch (sys.bugReports[i].bugSeverity)
				{
					case Severity::neutral:
						m_sev += ": neutral";
						break;
					case Severity::low:
						m_sev += ": low";
						break;
					case Severity::med:
						m_sev += ": med";
						break;
					case Severity::high:
						m_sev += ": high";
						break;
					case Severity::critical:
						m_sev += ": critical";
						break;
				}
				bugIDBox->Text = m_id;
				bugTitleBox->Text = m_title;
				bugCategoryBox->Text = m_cat;
				bugSeverityBox->Text = m_sev;
				bugInfoBox->Text = m_desc;
				bugReporterBox->Text = m_rep;
				bugAssigneeBox->Text = m_asg;
				createdBox->Text = m_cDate;
				updatedBox->Text = m_uDate;
			}
		}
	}

}

	   //submit the creation of a new bug report ->CREATE -> SUBMIT ->UPDATE DATA PASS -> FILL ACTIVE LOGS -> CLEAR FORM FOR NEW REPORT
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	DTS sys;

	//Conversion Examples
				/*
				//String^ to string
				//System::String^ xyz = "Hi";
				//std::string converted_xyz = msclr::interop::marshal_as< std::string >(xyz);
				//string to String^
				//string com = "Title: " + r.bugTitle + "Category: " + r.bugCategory + "Severity: ";
				//String^ compiledString = msclr::interop::marshal_as <String^>(com);
				*/
	List<String^>^ set = gcnew List <String^>();
	set->Add(titleBox->Text);
	set->Add(categoryBox->Text);
	set->Add(severityBox->Text);
	set->Add(reporterBox->Text);
	set->Add(assigneeBox->Text);
	set->Add(descBox->Text);
	DateTime now = DateTime().Now;
	loggerBox->Text += "TIMESTAMP: " + now.ToString("F") + reporterBox->Text + " created " + titleBox->Text + " :: " + severityBox->Text;
	string sTime = msclr::interop::marshal_as< std::string >(now.ToString("F"));

	string title = msclr::interop::marshal_as< std::string >(set[0]);
	string category = msclr::interop::marshal_as< std::string >(set[1]);
	string severity = msclr::interop::marshal_as< std::string >(set[2]);
	string reporter = msclr::interop::marshal_as< std::string >(set[3]);
	string assignee = msclr::interop::marshal_as< std::string >(set[4]);
	string description = msclr::interop::marshal_as< std::string >(set[5]);
	string logger = msclr::interop::marshal_as< std::string >(loggerBox->Text);
	DTS dts;
	dts.WriteToLog(logger);

	json temp = sys.GrabJsonFile();
	BugReport b = BugReport();
	if (severityBox->SelectedItem == severityBox->Items[0])
	{
		b.bugSeverity = Severity::neutral;
	}
	else if (severityBox->SelectedItem == severityBox->Items[1])
	{
		b.bugSeverity = Severity::low;
	}
	else if (severityBox->SelectedItem == severityBox->Items[2])
	{
		b.bugSeverity = Severity::med;
	}
	else if (severityBox->SelectedItem == severityBox->Items[3])
	{
		b.bugSeverity = Severity::high;
	}
	else if (severityBox->SelectedItem == severityBox->Items[4])
	{
		b.bugSeverity = Severity::critical;
	}
	sys.CreateBugReport(title, category, description, b.bugSeverity, reporter, assignee, sTime);
	UpdateActiveReports(sys);
	sys.CreateAndSaveJsonObject();
	titleBox->Text = "";
	categoryBox->Text = "";
	severityBox->Text = "";
	reporterBox->Text = "";
	assigneeBox->Text = "";
	descBox->Text = "";
	//loggerBox->Text = "";
}


private: System::Void output_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void exportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	cout << "Save clicked\n";
	DTS sys;
	sys.CreateAndSaveJsonObject();
}


private: System::Void deleteBugReport_Click(System::Object^ sender, System::EventArgs^ e) {
	if (bugIDBox->TextLength > 0)
	{
		string s = msclr::interop::marshal_as< std::string >(bugIDBox->Text);
		DTS sys;
		sys.FindAndDeleteBugReport(stoi(s));
		bugGrid->Rows->Clear();
		UpdateActiveReports(sys);
	}


}
private: System::Void categoryBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void resetForm_Click(System::Object^ sender, System::EventArgs^ e) {
	titleBox->Text = "";
	categoryBox->Text = "";
	severityBox->Text = "";
	reporterBox->Text = "";
	assigneeBox->Text = "";
	//this just re-adds some of the pre-made prompt info in the bug description, making it a big easier for reporters to get started
	descBox->Text = "Error Codes / Types:\r\n\r\nFunctions / Tasks Performed :\r\n\r\nExpected Result :\r\n\r\nActual Result :\r\n\r\nNotes:\r\n\r\n";


}
private: System::Void editBugReport_Click(System::Object^ sender, System::EventArgs^ e) {
	/*
	bugIDBox->ReadOnly = false;
	bugTitleBox->ReadOnly = false;
	bugCategoryBox->ReadOnly = false;
	bugSeverityBox->ReadOnly = false;
	bugInfoBox->ReadOnly = false;
	bugReporterBox->ReadOnly = false;
	bugAssigneeBox->ReadOnly = false;
	*/
	if (bugTitleBox->ReadOnly == true)
	{
		editBugReport->BackColor = Color::Gray;
		editBugReport->Text = "Edit";
		saveEditReport->Visible = false;
	}
	else if(bugTitleBox->ReadOnly == false)
	{
		editBugReport->BackColor = Color::Yellow;
		editBugReport->Text = "Editing";
		saveEditReport->Visible = true;
	}
	bugTitleBox->ReadOnly = !bugTitleBox->ReadOnly;
	bugCategoryBox->ReadOnly = !bugCategoryBox->ReadOnly;
	bugSeverityBox->ReadOnly = !bugSeverityBox->ReadOnly;
	bugInfoBox->ReadOnly = !bugInfoBox->ReadOnly;
	bugReporterBox->ReadOnly = !bugReporterBox->ReadOnly;
	bugAssigneeBox->ReadOnly = !bugAssigneeBox->ReadOnly;

	if (bugTitleBox->ReadOnly == true)
	{
		editBugReport->BackColor = Color::Transparent;
		editBugReport->Text = "Edit";
		saveEditReport->Visible = false;
	}
	else if (bugTitleBox->ReadOnly == false)
	{
		editBugReport->BackColor = Color::Yellow;
		editBugReport->Text = "Editing";
		saveEditReport->Visible = true;
	}
}
private: System::Void codeSnippets_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void saveEditReport_Click(System::Object^ sender, System::EventArgs^ e) {
	bugTitleBox->ReadOnly = true;
	bugCategoryBox->ReadOnly = true;
	bugSeverityBox->ReadOnly = true;
	bugInfoBox->ReadOnly = true;
	bugReporterBox->ReadOnly = true;
	bugAssigneeBox->ReadOnly = true;
	//setup a temp bug report to overwrite the old
	BugReport report = BugReport();
	string tSev = msclr::interop::marshal_as<string>(bugSeverityBox->Text);
	report.bugTitle = msclr::interop::marshal_as<string>(bugTitleBox->Text);
	report.bugCategory = msclr::interop::marshal_as<string>(bugCategoryBox->Text);
	int sev; 
	string t = "";
	t += tSev[0];
	if (stoi(t) == 0) //neutral
	{
		sev = 0;
	}
	else if (stoi(t) == 1) //low
	{
		sev = 1;
	}
	else if (stoi(t) == 2) //med
	{
		sev = 2;
	}
	else if (stoi(t) == 3) //high
	{
		sev = 3;
	}
	else if (stoi(t) == 4) //critical
	{
		sev = 4;
	}
	DateTime now = DateTime().Now;
	string sTime = msclr::interop::marshal_as<string>(now.ToString("F"));
	report.bugDescription = msclr::interop::marshal_as<string>(bugInfoBox->Text);
	report.bugReporter = msclr::interop::marshal_as<string>(bugReporterBox->Text);
	report.bugAssignee = msclr::interop::marshal_as<string>(bugAssigneeBox->Text);
	report.dateCreated = msclr::interop::marshal_as<string>(createdBox->Text);
	report.lastUpdate = sTime;
	report.SetSeverity(sev);
	string m_id = msclr::interop::marshal_as <string>(bugIDBox->Text);

	int tID = stoi(m_id);
	report.bugID = tID;
	DTS sys;
	sys.GrabReportList();

	sys.FindAndUpdateBugReporter(tID, report);
	bugGrid->Rows->Clear();
	// Get the full row of the clicked cell.
	UpdateActiveReports(sys);
	DataGridViewRow^ row = bugGrid->Rows[rowIndex];
	row->Cells[0]->Value = report.bugID;
	row->Cells[1]->Value = msclr::interop::marshal_as<String^>(report.bugTitle);
	row->Cells[2]->Value = msclr::interop::marshal_as<String^>(report.bugCategory);
	row->Cells[3]->Value = msclr::interop::marshal_as<String^>(to_string(report.bugSeverity));
	row->Cells[4]->Value = msclr::interop::marshal_as<String^>(report.bugDescription);
	row->Cells[5]->Value = msclr::interop::marshal_as<String^>(report.bugReporter);
	row->Cells[6]->Value = msclr::interop::marshal_as<String^>(report.bugAssignee);
	row->Cells[7]->Value = msclr::interop::marshal_as<String^>(report.dateCreated);
	row->Cells[8]->Value = msclr::interop::marshal_as<String^>(report.lastUpdate);
	editBugReport->BackColor = Color::Transparent;
	editBugReport->Text = "Edit";
	saveEditReport->Visible = false;
	cout << "\nReport Saved";
}
private: System::Void reportDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Process ^process = gcnew Process();
	process->StartInfo->FileName = "notepad.exe";
	process->StartInfo->Arguments = "bug_reports.json";
	process->Start();
}
private: System::Void loggerDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Process^ process = gcnew Process();
	process->StartInfo->FileName = "notepad.exe";
	process->StartInfo->Arguments = "dts_syslog.txt";
	process->Start();
}

private: System::Void fileFolderToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
	String^ programPath = System::Reflection::Assembly::GetExecutingAssembly()->Location;

	String^ programDirectory = Path::GetDirectoryName(programPath);

	Process^ process = gcnew Process();
	process->StartInfo->FileName = "explorer.exe";
	process->StartInfo->Arguments = programDirectory;
	process->Start();
}
};
}
