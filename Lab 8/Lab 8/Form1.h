#pragma once
	#include "PlaneSimRun.h"

namespace Lab8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace CS262;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  landingTimeTB;
	protected: 

	protected: 

	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  takeoffTimeTB;



	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  airTimeTB;

	private: System::Windows::Forms::TextBox^  averageTimeBetweenArrivalsTB;

	private: System::Windows::Forms::TextBox^  averageTimeBetweenDeparturesTB;

	private: System::Windows::Forms::TextBox^  stepsTB;









	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  simulationParameters;
	private: System::Windows::Forms::GroupBox^  simulationResults;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  averageLandWaitTB;

	private: System::Windows::Forms::TextBox^  averageTakeoffWaitTB;


	private: System::Windows::Forms::TextBox^  waitingToLandTB;


	private: System::Windows::Forms::TextBox^  waitingToTakeoffTB;



	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  arrivalsTB;


	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  departuresTB;



	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::Button^  runButton;




	protected: 


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->landingTimeTB = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->takeoffTimeTB = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->airTimeTB = (gcnew System::Windows::Forms::TextBox());
			this->averageTimeBetweenArrivalsTB = (gcnew System::Windows::Forms::TextBox());
			this->averageTimeBetweenDeparturesTB = (gcnew System::Windows::Forms::TextBox());
			this->stepsTB = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->simulationParameters = (gcnew System::Windows::Forms::GroupBox());
			this->simulationResults = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->averageLandWaitTB = (gcnew System::Windows::Forms::TextBox());
			this->averageTakeoffWaitTB = (gcnew System::Windows::Forms::TextBox());
			this->waitingToLandTB = (gcnew System::Windows::Forms::TextBox());
			this->waitingToTakeoffTB = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->arrivalsTB = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->departuresTB = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->runButton = (gcnew System::Windows::Forms::Button());
			this->simulationParameters->SuspendLayout();
			this->simulationResults->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// landingTimeTB
			// 
			this->landingTimeTB->Location = System::Drawing::Point(241, 23);
			this->landingTimeTB->Name = L"landingTimeTB";
			this->landingTimeTB->Size = System::Drawing::Size(100, 20);
			this->landingTimeTB->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Time for plane to land:";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Time for plane to take off:";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(216, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Time plance can stay in air without crashing:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 98);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(152, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Average time between arrivals:";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// takeoffTimeTB
			// 
			this->takeoffTimeTB->Location = System::Drawing::Point(241, 47);
			this->takeoffTimeTB->Name = L"takeoffTimeTB";
			this->takeoffTimeTB->Size = System::Drawing::Size(100, 20);
			this->takeoffTimeTB->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 122);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(169, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Average time between departures:";
			// 
			// airTimeTB
			// 
			this->airTimeTB->Location = System::Drawing::Point(241, 71);
			this->airTimeTB->Name = L"airTimeTB";
			this->airTimeTB->Size = System::Drawing::Size(100, 20);
			this->airTimeTB->TabIndex = 10;
			// 
			// averageTimeBetweenArrivalsTB
			// 
			this->averageTimeBetweenArrivalsTB->Location = System::Drawing::Point(241, 95);
			this->averageTimeBetweenArrivalsTB->Name = L"averageTimeBetweenArrivalsTB";
			this->averageTimeBetweenArrivalsTB->Size = System::Drawing::Size(100, 20);
			this->averageTimeBetweenArrivalsTB->TabIndex = 2;
			// 
			// averageTimeBetweenDeparturesTB
			// 
			this->averageTimeBetweenDeparturesTB->Location = System::Drawing::Point(241, 119);
			this->averageTimeBetweenDeparturesTB->Name = L"averageTimeBetweenDeparturesTB";
			this->averageTimeBetweenDeparturesTB->Size = System::Drawing::Size(100, 20);
			this->averageTimeBetweenDeparturesTB->TabIndex = 4;
			// 
			// stepsTB
			// 
			this->stepsTB->Location = System::Drawing::Point(241, 143);
			this->stepsTB->Name = L"stepsTB";
			this->stepsTB->Size = System::Drawing::Size(100, 20);
			this->stepsTB->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Steps in simulation:";
			// 
			// simulationParameters
			// 
			this->simulationParameters->Controls->Add(this->label4);
			this->simulationParameters->Controls->Add(this->stepsTB);
			this->simulationParameters->Controls->Add(this->averageTimeBetweenDeparturesTB);
			this->simulationParameters->Controls->Add(this->averageTimeBetweenArrivalsTB);
			this->simulationParameters->Controls->Add(this->airTimeTB);
			this->simulationParameters->Controls->Add(this->label5);
			this->simulationParameters->Controls->Add(this->takeoffTimeTB);
			this->simulationParameters->Controls->Add(this->label6);
			this->simulationParameters->Controls->Add(this->label3);
			this->simulationParameters->Controls->Add(this->label2);
			this->simulationParameters->Controls->Add(this->label1);
			this->simulationParameters->Controls->Add(this->landingTimeTB);
			this->simulationParameters->Location = System::Drawing::Point(12, 37);
			this->simulationParameters->Name = L"simulationParameters";
			this->simulationParameters->Size = System::Drawing::Size(347, 166);
			this->simulationParameters->TabIndex = 1;
			this->simulationParameters->TabStop = false;
			this->simulationParameters->Tag = L"";
			this->simulationParameters->Text = L"Simulation Parameters";
			this->simulationParameters->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// simulationResults
			// 
			this->simulationResults->Controls->Add(this->label7);
			this->simulationResults->Controls->Add(this->averageLandWaitTB);
			this->simulationResults->Controls->Add(this->averageTakeoffWaitTB);
			this->simulationResults->Controls->Add(this->waitingToLandTB);
			this->simulationResults->Controls->Add(this->waitingToTakeoffTB);
			this->simulationResults->Controls->Add(this->label8);
			this->simulationResults->Controls->Add(this->arrivalsTB);
			this->simulationResults->Controls->Add(this->label9);
			this->simulationResults->Controls->Add(this->label10);
			this->simulationResults->Controls->Add(this->label11);
			this->simulationResults->Controls->Add(this->label12);
			this->simulationResults->Controls->Add(this->departuresTB);
			this->simulationResults->Location = System::Drawing::Point(12, 224);
			this->simulationResults->Name = L"simulationResults";
			this->simulationResults->Size = System::Drawing::Size(347, 166);
			this->simulationResults->TabIndex = 2;
			this->simulationResults->TabStop = false;
			this->simulationResults->Tag = L"";
			this->simulationResults->Text = L"Simulation Results";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 146);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(107, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Average wait to land:";
			// 
			// averageLandWaitTB
			// 
			this->averageLandWaitTB->Location = System::Drawing::Point(241, 143);
			this->averageLandWaitTB->Name = L"averageLandWaitTB";
			this->averageLandWaitTB->Size = System::Drawing::Size(100, 20);
			this->averageLandWaitTB->TabIndex = 6;
			// 
			// averageTakeoffWaitTB
			// 
			this->averageTakeoffWaitTB->Location = System::Drawing::Point(241, 119);
			this->averageTakeoffWaitTB->Name = L"averageTakeoffWaitTB";
			this->averageTakeoffWaitTB->Size = System::Drawing::Size(100, 20);
			this->averageTakeoffWaitTB->TabIndex = 4;
			// 
			// waitingToLandTB
			// 
			this->waitingToLandTB->Location = System::Drawing::Point(241, 95);
			this->waitingToLandTB->Name = L"waitingToLandTB";
			this->waitingToLandTB->Size = System::Drawing::Size(100, 20);
			this->waitingToLandTB->TabIndex = 2;
			this->waitingToLandTB->TextChanged += gcnew System::EventHandler(this, &Form1::waitingToLand_TextChanged);
			// 
			// waitingToTakeoffTB
			// 
			this->waitingToTakeoffTB->Location = System::Drawing::Point(241, 71);
			this->waitingToTakeoffTB->Name = L"waitingToTakeoffTB";
			this->waitingToTakeoffTB->Size = System::Drawing::Size(100, 20);
			this->waitingToTakeoffTB->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 122);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(123, 13);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Average wait to take off:";
			// 
			// arrivalsTB
			// 
			this->arrivalsTB->Location = System::Drawing::Point(241, 47);
			this->arrivalsTB->Name = L"arrivalsTB";
			this->arrivalsTB->Size = System::Drawing::Size(100, 20);
			this->arrivalsTB->TabIndex = 8;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 98);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(81, 13);
			this->label9->TabIndex = 7;
			this->label9->Text = L"Waiting to land:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 74);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(97, 13);
			this->label10->TabIndex = 5;
			this->label10->Text = L"Waiting for takeoff:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 50);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(44, 13);
			this->label11->TabIndex = 3;
			this->label11->Text = L"Arrivals:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 26);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(62, 13);
			this->label12->TabIndex = 1;
			this->label12->Text = L"Departures:";
			// 
			// departuresTB
			// 
			this->departuresTB->Location = System::Drawing::Point(241, 23);
			this->departuresTB->Name = L"departuresTB";
			this->departuresTB->Size = System::Drawing::Size(100, 20);
			this->departuresTB->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(371, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// runButton
			// 
			this->runButton->Location = System::Drawing::Point(12, 396);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(346, 25);
			this->runButton->TabIndex = 4;
			this->runButton->Text = L"Let em\' Fly!";
			this->runButton->UseVisualStyleBackColor = true;
			this->runButton->Click += gcnew System::EventHandler(this, &Form1::runButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(371, 427);
			this->Controls->Add(this->runButton);
			this->Controls->Add(this->simulationResults);
			this->Controls->Add(this->simulationParameters);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->simulationParameters->ResumeLayout(false);
			this->simulationParameters->PerformLayout();
			this->simulationResults->ResumeLayout(false);
			this->simulationResults->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
			}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void runButton_Click(System::Object^  sender, System::EventArgs^  e) {
				double values[6];
				RunPlaneSim(Convert::ToInt32(landingTimeTB->Text), Convert::ToInt32(takeoffTimeTB->Text), Convert::ToInt32(airTimeTB->Text), Convert::ToInt32(averageTimeBetweenArrivalsTB->Text), Convert::ToInt32(averageTimeBetweenDeparturesTB->Text), Convert::ToInt32(stepsTB->Text));
				departuresTB->Text = Convert::ToString(values[0]);
				arrivalsTB->Text =  Convert::ToString(values[1]);
				waitingToTakeoffTB->Text = Convert::ToString(values[2]);
				waitingToLandTB->Text = Convert::ToString(values[3]);
				averageTakeoffWaitTB->Text = Convert::ToString(values[4]);
				averageLandWaitTB->Text = Convert::ToString(values[5]);
			}
private: System::Void waitingToLand_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			}
};
}

