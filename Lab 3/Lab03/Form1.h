#pragma once
#include "MyRect.h"
#include "DrawList.h"

namespace ProgramForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CS262;

	// current rectangle being created
	MyRect myRect;

	// current drawing attributes
	CS262::Point startPoint;
	CS262::Color drawColor;
	bool drawFilled = true;

	// list of rectangles
	DrawList list;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Scene : public System::Windows::Forms::Form
	{
	public:
		Scene(void)
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
		~Scene()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  drawingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  filledToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  setColorToolStripMenuItem;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		void Draw( Graphics^ g );
		void Scene::Init( );

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drawingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filledToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->drawingToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(584, 24);
			this->menuStrip1->TabIndex = 0;
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
			this->exitToolStripMenuItem->ShortcutKeyDisplayString = L"Esc";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Scene::exitToolStripMenuItem_Click);
			// 
			// drawingToolStripMenuItem
			// 
			this->drawingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->filledToolStripMenuItem, 
				this->setColorToolStripMenuItem});
			this->drawingToolStripMenuItem->Name = L"drawingToolStripMenuItem";
			this->drawingToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->drawingToolStripMenuItem->Text = L"Drawing";
			// 
			// filledToolStripMenuItem
			// 
			this->filledToolStripMenuItem->Name = L"filledToolStripMenuItem";
			this->filledToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F));
			this->filledToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->filledToolStripMenuItem->Text = L"Set Filled";
			this->filledToolStripMenuItem->Click += gcnew System::EventHandler(this, &Scene::setFilledToolStripMenuItem_Click);
			// 
			// setColorToolStripMenuItem
			// 
			this->setColorToolStripMenuItem->Name = L"setColorToolStripMenuItem";
			this->setColorToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::C));
			this->setColorToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->setColorToolStripMenuItem->Text = L"Set Color";
			this->setColorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Scene::setColorToolStripMenuItem_Click);
			// 
			// colorDialog1
			// 
			this->colorDialog1->AnyColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 23);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(584, 339);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Scene::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Scene::pictureBox1_MouseDown);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Scene::pictureBox1_MouseUp);
			// 
			// Scene
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 362);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Scene";
			this->Text = L"Form1";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Scene::Scene_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void setFilledToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 drawFilled = !drawFilled;
			 }

	private: System::Void setColorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->colorDialog1->ShowHelp = true;
				 this->colorDialog1->Color = drawColor.getNetColor();

				 if (this->colorDialog1->ShowDialog() == 
					 System::Windows::Forms::DialogResult::OK)
				 {
					 drawColor.setColor(colorDialog1->Color);

				 }
				 pictureBox1->Invalidate();
			 }

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				Application::Exit();
			 }

	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 startPoint = CS262::Point(Convert::ToSingle(e->X), Convert::ToSingle(e->Y));
			 }

	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 myRect.setPoint1(startPoint);
				 myRect.setPoint2(CS262::Point(Convert::ToSingle(e->X), Convert::ToSingle(e->Y)));
				 myRect.setColor(drawColor);
				 myRect.setFilled(drawFilled);

				 // Now insert myRect into the list 
				 list.insert(myRect);

				 pictureBox1->Invalidate();
			 }

	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 __super::OnPaint( e );	

			 // Need graphics context for drawing				 
			 Graphics^ g = e->Graphics;
			 Draw( g );
		 }

	private: System::Void Scene_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == System::Windows::Forms::Keys::Delete && list.size() > 0)
			 {
				 list.remove_last();
				 this->pictureBox1->Invalidate();
			 }
			 else if (e->KeyCode == System::Windows::Forms::Keys::Escape)
			 {
				 Application::Exit();
			 }
		 }
};
}

