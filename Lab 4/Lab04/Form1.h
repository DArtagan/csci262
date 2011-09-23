#pragma once
#include "MyRect.h"
#include "MyOval.h"
#include "MyLine.h"
#include "DrawList.h"

namespace ProgramForm {
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace CS262;

	// current drawing attributes
	CS262::Point start_point;
	CS262::Color draw_color(255, 0, 0);
	bool draw_filled = true;

	// list of shapes
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

	private: System::Windows::Forms::MenuStrip^  menu_bar;
	private: System::Windows::Forms::ToolStripMenuItem^  file_menu;
	private: System::Windows::Forms::ToolStripMenuItem^  exit_menu_item;
	private: System::Windows::Forms::ToolStripMenuItem^  drawing_menu;
	private: System::Windows::Forms::ToolStripMenuItem^  filled_menu_item;
	private: System::Windows::Forms::ToolStripMenuItem^  color_menu_item;
	private: System::Windows::Forms::ColorDialog^  color_dialog;
	private: System::Windows::Forms::PictureBox^  drawing_area;
	private: System::Windows::Forms::CheckBox^  filled_checkbox;
	private: System::Windows::Forms::ToolStripMenuItem^  shape_menu_item;
	private: System::Windows::Forms::RadioButton^  line_radio;
	private: System::Windows::Forms::RadioButton^  oval_radio;
	private: System::Windows::Forms::RadioButton^  rectangle_radio;
	private: System::Windows::Forms::Button^  color_button;
	private: System::Windows::Forms::ToolStripMenuItem^  rectangle_menu_item;
	private: System::Windows::Forms::ToolStripMenuItem^  oval_menu_item;
	private: System::Windows::Forms::ToolStripMenuItem^  line_menu_item;
	private: System::Windows::Forms::ContextMenuStrip^  drawing_context_menu;
	private: System::Windows::Forms::ToolStripMenuItem^  filled_context_menu_item;
	private: System::Windows::Forms::ToolStripMenuItem^  color_context_menu_item;
	private: System::Windows::Forms::ToolStripMenuItem^  shape_context_menu_item;
	private: System::Windows::Forms::ToolStripMenuItem^  rectangle_context_menu_item;
	private: System::Windows::Forms::ToolStripMenuItem^  oval_context_menu_item;
	private: System::Windows::Forms::ToolStripMenuItem^  line_context_menu_item;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


		void Draw(Graphics^ g);
		void set_shape_menu_selection(ToolStripMenuItem^ active, ToolStripMenuItem^ o1, ToolStripMenuItem^ o2)  {
			active->Checked = true;
			o1->Checked = false;
			o2->Checked = false;
		}


		void set_radio_items_selection(RadioButton^ active, RadioButton^ o1, RadioButton^ o2)  {
			active->Checked = true;
			o1->Checked = false;
			o2->Checked = false;
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menu_bar = (gcnew System::Windows::Forms::MenuStrip());
			this->file_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exit_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drawing_menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filled_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->color_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->shape_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rectangle_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oval_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->line_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->color_dialog = (gcnew System::Windows::Forms::ColorDialog());
			this->drawing_area = (gcnew System::Windows::Forms::PictureBox());
			this->drawing_context_menu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->filled_context_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->color_context_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->shape_context_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rectangle_context_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oval_context_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->line_context_menu_item = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filled_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->line_radio = (gcnew System::Windows::Forms::RadioButton());
			this->oval_radio = (gcnew System::Windows::Forms::RadioButton());
			this->rectangle_radio = (gcnew System::Windows::Forms::RadioButton());
			this->color_button = (gcnew System::Windows::Forms::Button());
			this->menu_bar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->drawing_area))->BeginInit();
			this->drawing_context_menu->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu_bar
			// 
			this->menu_bar->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->menu_bar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->file_menu, this->drawing_menu});
			this->menu_bar->Location = System::Drawing::Point(0, 0);
			this->menu_bar->Name = L"menu_bar";
			this->menu_bar->Size = System::Drawing::Size(584, 24);
			this->menu_bar->TabIndex = 0;
			this->menu_bar->Text = L"menuStrip1";
			// 
			// file_menu
			// 
			this->file_menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exit_menu_item});
			this->file_menu->Name = L"file_menu";
			this->file_menu->Size = System::Drawing::Size(37, 20);
			this->file_menu->Text = L"File";
			// 
			// exit_menu_item
			// 
			this->exit_menu_item->Name = L"exit_menu_item";
			this->exit_menu_item->ShortcutKeyDisplayString = L"Esc";
			this->exit_menu_item->Size = System::Drawing::Size(116, 22);
			this->exit_menu_item->Text = L"Exit";
			this->exit_menu_item->Click += gcnew System::EventHandler(this, &Scene::exit_program);
			// 
			// drawing_menu
			// 
			this->drawing_menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->filled_menu_item, 
				this->color_menu_item, this->shape_menu_item});
			this->drawing_menu->Name = L"drawing_menu";
			this->drawing_menu->Size = System::Drawing::Size(63, 20);
			this->drawing_menu->Text = L"Drawing";
			// 
			// filled_menu_item
			// 
			this->filled_menu_item->Checked = true;
			this->filled_menu_item->CheckOnClick = true;
			this->filled_menu_item->CheckState = System::Windows::Forms::CheckState::Checked;
			this->filled_menu_item->Name = L"filled_menu_item";
			this->filled_menu_item->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F));
			this->filled_menu_item->Size = System::Drawing::Size(160, 22);
			this->filled_menu_item->Text = L"Set Filled";
			this->filled_menu_item->Click += gcnew System::EventHandler(this, &Scene::filled_toggle);
			// 
			// color_menu_item
			// 
			this->color_menu_item->Name = L"color_menu_item";
			this->color_menu_item->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::C));
			this->color_menu_item->Size = System::Drawing::Size(160, 22);
			this->color_menu_item->Text = L"Set Color";
			this->color_menu_item->Click += gcnew System::EventHandler(this, &Scene::set_color);
			// 
			// shape_menu_item
			// 
			this->shape_menu_item->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->rectangle_menu_item, 
				this->oval_menu_item, this->line_menu_item});
			this->shape_menu_item->Name = L"shape_menu_item";
			this->shape_menu_item->Size = System::Drawing::Size(160, 22);
			this->shape_menu_item->Text = L"Shape";
			// 
			// rectangle_menu_item
			// 
			this->rectangle_menu_item->Checked = true;
			this->rectangle_menu_item->CheckOnClick = true;
			this->rectangle_menu_item->CheckState = System::Windows::Forms::CheckState::Checked;
			this->rectangle_menu_item->Name = L"rectangle_menu_item";
			this->rectangle_menu_item->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::R));
			this->rectangle_menu_item->Size = System::Drawing::Size(163, 22);
			this->rectangle_menu_item->Text = L"Rectangle";
			this->rectangle_menu_item->Click += gcnew System::EventHandler(this, &Scene::rectangle_select);
			// 
			// oval_menu_item
			// 
			this->oval_menu_item->CheckOnClick = true;
			this->oval_menu_item->Name = L"oval_menu_item";
			this->oval_menu_item->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::O));
			this->oval_menu_item->Size = System::Drawing::Size(163, 22);
			this->oval_menu_item->Text = L"Oval";
			this->oval_menu_item->Click += gcnew System::EventHandler(this, &Scene::oval_select);
			// 
			// line_menu_item
			// 
			this->line_menu_item->CheckOnClick = true;
			this->line_menu_item->Name = L"line_menu_item";
			this->line_menu_item->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::L));
			this->line_menu_item->Size = System::Drawing::Size(163, 22);
			this->line_menu_item->Text = L"Line";
			this->line_menu_item->Click += gcnew System::EventHandler(this, &Scene::line_select);
			// 
			// color_dialog
			// 
			this->color_dialog->AnyColor = true;
			// 
			// drawing_area
			// 
			this->drawing_area->BackColor = System::Drawing::SystemColors::Window;
			this->drawing_area->ContextMenuStrip = this->drawing_context_menu;
			this->drawing_area->Dock = System::Windows::Forms::DockStyle::Fill;
			this->drawing_area->Location = System::Drawing::Point(0, 24);
			this->drawing_area->Name = L"drawing_area";
			this->drawing_area->Size = System::Drawing::Size(584, 338);
			this->drawing_area->TabIndex = 1;
			this->drawing_area->TabStop = false;
			this->drawing_area->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Scene::drawing_area_paint);
			this->drawing_area->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Scene::drawing_area_mouse_down);
			this->drawing_area->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Scene::drawing_area_mouse_up);
			// 
			// drawing_context_menu
			// 
			this->drawing_context_menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->filled_context_menu_item, 
				this->color_context_menu_item, this->shape_context_menu_item});
			this->drawing_context_menu->Name = L"drawing_context_menu";
			this->drawing_context_menu->Size = System::Drawing::Size(123, 70);
			// 
			// filled_context_menu_item
			// 
			this->filled_context_menu_item->Checked = true;
			this->filled_context_menu_item->CheckState = System::Windows::Forms::CheckState::Checked;
			this->filled_context_menu_item->Name = L"filled_context_menu_item";
			this->filled_context_menu_item->Size = System::Drawing::Size(122, 22);
			this->filled_context_menu_item->Text = L"Set Filled";
			this->filled_context_menu_item->Click += gcnew System::EventHandler(this, &Scene::filled_toggle);
			// 
			// color_context_menu_item
			// 
			this->color_context_menu_item->Name = L"color_context_menu_item";
			this->color_context_menu_item->Size = System::Drawing::Size(122, 22);
			this->color_context_menu_item->Text = L"Set Color";
			this->color_context_menu_item->Click += gcnew System::EventHandler(this, &Scene::set_color);
			// 
			// shape_context_menu_item
			// 
			this->shape_context_menu_item->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->rectangle_context_menu_item, 
				this->oval_context_menu_item, this->line_context_menu_item});
			this->shape_context_menu_item->Name = L"shape_context_menu_item";
			this->shape_context_menu_item->Size = System::Drawing::Size(122, 22);
			this->shape_context_menu_item->Text = L"Shape";
			// 
			// rectangle_context_menu_item
			// 
			this->rectangle_context_menu_item->Checked = true;
			this->rectangle_context_menu_item->CheckState = System::Windows::Forms::CheckState::Checked;
			this->rectangle_context_menu_item->Name = L"rectangle_context_menu_item";
			this->rectangle_context_menu_item->Size = System::Drawing::Size(126, 22);
			this->rectangle_context_menu_item->Text = L"Rectangle";
			this->rectangle_context_menu_item->Click += gcnew System::EventHandler(this, &Scene::rectangle_select);
			// 
			// oval_context_menu_item
			// 
			this->oval_context_menu_item->Name = L"oval_context_menu_item";
			this->oval_context_menu_item->Size = System::Drawing::Size(126, 22);
			this->oval_context_menu_item->Text = L"Oval";
			this->oval_context_menu_item->Click += gcnew System::EventHandler(this, &Scene::oval_select);
			// 
			// line_context_menu_item
			// 
			this->line_context_menu_item->Name = L"line_context_menu_item";
			this->line_context_menu_item->Size = System::Drawing::Size(126, 22);
			this->line_context_menu_item->Text = L"Line";
			this->line_context_menu_item->Click += gcnew System::EventHandler(this, &Scene::line_select);
			// 
			// filled_checkbox
			// 
			this->filled_checkbox->AutoSize = true;
			this->filled_checkbox->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->filled_checkbox->Checked = true;
			this->filled_checkbox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->filled_checkbox->Location = System::Drawing::Point(522, 5);
			this->filled_checkbox->Name = L"filled_checkbox";
			this->filled_checkbox->Size = System::Drawing::Size(50, 17);
			this->filled_checkbox->TabIndex = 2;
			this->filled_checkbox->Text = L"Filled";
			this->filled_checkbox->UseVisualStyleBackColor = false;
			this->filled_checkbox->Click += gcnew System::EventHandler(this, &Scene::filled_toggle);
			// 
			// line_radio
			// 
			this->line_radio->AutoCheck = false;
			this->line_radio->AutoSize = true;
			this->line_radio->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->line_radio->Location = System::Drawing::Point(442, 4);
			this->line_radio->Name = L"line_radio";
			this->line_radio->Size = System::Drawing::Size(45, 17);
			this->line_radio->TabIndex = 3;
			this->line_radio->Text = L"Line";
			this->line_radio->UseVisualStyleBackColor = false;
			this->line_radio->Click += gcnew System::EventHandler(this, &Scene::line_select);
			// 
			// oval_radio
			// 
			this->oval_radio->AutoCheck = false;
			this->oval_radio->AutoSize = true;
			this->oval_radio->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->oval_radio->Location = System::Drawing::Point(378, 4);
			this->oval_radio->Name = L"oval_radio";
			this->oval_radio->Size = System::Drawing::Size(47, 17);
			this->oval_radio->TabIndex = 4;
			this->oval_radio->Text = L"Oval";
			this->oval_radio->UseVisualStyleBackColor = false;
			this->oval_radio->Click += gcnew System::EventHandler(this, &Scene::oval_select);
			// 
			// rectangle_radio
			// 
			this->rectangle_radio->AutoCheck = false;
			this->rectangle_radio->AutoSize = true;
			this->rectangle_radio->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->rectangle_radio->Checked = true;
			this->rectangle_radio->Location = System::Drawing::Point(285, 4);
			this->rectangle_radio->Name = L"rectangle_radio";
			this->rectangle_radio->Size = System::Drawing::Size(74, 17);
			this->rectangle_radio->TabIndex = 5;
			this->rectangle_radio->TabStop = true;
			this->rectangle_radio->Text = L"Rectangle";
			this->rectangle_radio->UseVisualStyleBackColor = false;
			this->rectangle_radio->Click += gcnew System::EventHandler(this, &Scene::rectangle_select);
			// 
			// color_button
			// 
			this->color_button->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->color_button->FlatAppearance->BorderColor = System::Drawing::SystemColors::ButtonShadow;
			this->color_button->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->color_button->Location = System::Drawing::Point(183, 1);
			this->color_button->Margin = System::Windows::Forms::Padding(2);
			this->color_button->Name = L"color_button";
			this->color_button->Size = System::Drawing::Size(75, 21);
			this->color_button->TabIndex = 6;
			this->color_button->Text = L"Color";
			this->color_button->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->color_button->UseVisualStyleBackColor = false;
			this->color_button->Click += gcnew System::EventHandler(this, &Scene::set_color);
			// 
			// Scene
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 362);
			this->Controls->Add(this->color_button);
			this->Controls->Add(this->rectangle_radio);
			this->Controls->Add(this->oval_radio);
			this->Controls->Add(this->line_radio);
			this->Controls->Add(this->filled_checkbox);
			this->Controls->Add(this->drawing_area);
			this->Controls->Add(this->menu_bar);
			this->KeyPreview = true;
			this->MainMenuStrip = this->menu_bar;
			this->MinimumSize = System::Drawing::Size(600, 400);
			this->Name = L"Scene";
			this->Text = L"Drawing Program";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Scene::Scene_KeyDown);
			this->menu_bar->ResumeLayout(false);
			this->menu_bar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->drawing_area))->EndInit();
			this->drawing_context_menu->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void set_color(System::Object^  sender, System::EventArgs^  e) {
				 color_dialog->ShowHelp = true;
				 color_dialog->Color = draw_color.getNetColor();

				 if (color_dialog->ShowDialog() == 
					 System::Windows::Forms::DialogResult::OK)
				 {
					 draw_color.setColor(color_dialog->Color);

				 }
				 drawing_area->Invalidate();
			 }

	private: System::Void exit_program(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }

	private: System::Void drawing_area_mouse_down(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 start_point = CS262::Point(Convert::ToSingle(e->X), Convert::ToSingle(e->Y));
			 }

	private: System::Void drawing_area_mouse_up(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if (e->Button == System::Windows::Forms::MouseButtons::Left)
				 {
					 CS262::Point end_point = CS262::Point(
						 Convert::ToSingle(e->X),
						 Convert::ToSingle(e->Y));

					 MyShape* shape;

					 if (line_radio->Checked) {
						 shape = new MyLine(start_point, end_point, draw_color);
					 } else if (oval_radio->Checked) {
						 shape = new MyOval(start_point, end_point, draw_color, draw_filled);
					 } else {
						 shape = new MyRect(start_point, end_point, draw_color, draw_filled);
					 }

					 list.insert(shape);

					 delete shape;

					 drawing_area->Invalidate();
				 }
			 }

	private: System::Void drawing_area_paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 __super::OnPaint(e);	
				 Draw(e->Graphics);
			 }

	private: System::Void Scene_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if (e->KeyCode == Keys::Delete || e->KeyCode == Keys::D)
				 {
					 if (list.size() > 0) {
						 list.remove_last();
						 drawing_area->Invalidate();
					 }
				 }
				 else if (e->KeyCode == Keys::Escape)
				 {
					 Application::Exit();
				 }
			 }

	private: System::Void filled_toggle(System::Object^  sender, System::EventArgs^  e) {
				 draw_filled = !draw_filled;
				 filled_checkbox->Checked = draw_filled;
				 filled_menu_item->Checked = draw_filled;
				 filled_context_menu_item->Checked = draw_filled;
			 }

	private: System::Void rectangle_select(System::Object^  sender, System::EventArgs^  e) {
				 set_shape_menu_selection(rectangle_menu_item, oval_menu_item, line_menu_item);
				 set_shape_menu_selection(rectangle_context_menu_item, oval_context_menu_item, line_context_menu_item);
				 set_radio_items_selection(rectangle_radio, oval_radio, line_radio);
			 }

	private: System::Void oval_select(System::Object^  sender, System::EventArgs^  e) {
				 set_shape_menu_selection(oval_menu_item, line_menu_item, rectangle_menu_item);
				 set_shape_menu_selection(oval_context_menu_item, line_context_menu_item, rectangle_context_menu_item);
				 set_radio_items_selection(oval_radio, line_radio, rectangle_radio);
			 }

	private: System::Void line_select(System::Object^  sender, System::EventArgs^  e) {
				 set_shape_menu_selection(line_menu_item, rectangle_menu_item, oval_menu_item);
				 set_shape_menu_selection(line_context_menu_item, rectangle_context_menu_item, oval_context_menu_item);
				 set_radio_items_selection(line_radio, rectangle_radio, oval_radio);
			 }
	};
}

