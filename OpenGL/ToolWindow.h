#pragma once

namespace PrimitiveDrawTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ToolWindow : public System::Windows::Forms::Form
	{
	public:
		// Public static values read by GameController
		static float YValue;      // range 0..200, default 100
		static float UValue;
		static float VValue;
		static bool  InvertColors;

		ToolWindow(void)
		{
			InitializeComponent();
			// initialize UI -> static values
			UpdateValues();
		}

	protected:
		~ToolWindow()
		{
			// keep components for proper disposal (designer pattern)
			if (components)
			{
				delete components;
			}
		}

	private:
		// keep a components container for garbage collection / disposal
		System::ComponentModel::Container^ components;

		// Trackbars and labels (left labels already exist in your design)
		System::Windows::Forms::TrackBar^ trackBarY;
		System::Windows::Forms::TrackBar^ trackBarU;
		System::Windows::Forms::TrackBar^ trackBarV;

		System::Windows::Forms::Label^ labelY;
		System::Windows::Forms::Label^ labelU;
		System::Windows::Forms::Label^ labelV;

		// percent readouts on the right (new)
		System::Windows::Forms::Label^ labelYVal;
		System::Windows::Forms::Label^ labelUVal;
		System::Windows::Forms::Label^ labelVVal;

		// invert checkbox
		System::Windows::Forms::CheckBox^ checkBoxInvert;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->trackBarY = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarU = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarV = (gcnew System::Windows::Forms::TrackBar());
			this->labelY = (gcnew System::Windows::Forms::Label());
			this->labelU = (gcnew System::Windows::Forms::Label());
			this->labelV = (gcnew System::Windows::Forms::Label());
			this->labelYVal = (gcnew System::Windows::Forms::Label());
			this->labelUVal = (gcnew System::Windows::Forms::Label());
			this->labelVVal = (gcnew System::Windows::Forms::Label());
			this->checkBoxInvert = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarU))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarV))->BeginInit();
			this->SuspendLayout();
			// 
			// trackBarY
			// 
			this->trackBarY->LargeChange = 10;
			this->trackBarY->Location = System::Drawing::Point(40, 15);
			this->trackBarY->Maximum = 200;
			this->trackBarY->Name = L"trackBarY";
			this->trackBarY->Size = System::Drawing::Size(431, 45);
			this->trackBarY->TabIndex = 1;
			this->trackBarY->TickFrequency = 10;
			this->trackBarY->Value = 100;
			this->trackBarY->Scroll += gcnew System::EventHandler(this, &ToolWindow::OnTrackBarScroll);
			// 
			// trackBarU
			// 
			this->trackBarU->Location = System::Drawing::Point(40, 65);
			this->trackBarU->Maximum = 200;
			this->trackBarU->Name = L"trackBarU";
			this->trackBarU->Size = System::Drawing::Size(431, 45);
			this->trackBarU->TabIndex = 4;
			this->trackBarU->TickFrequency = 10;
			this->trackBarU->Value = 100;
			this->trackBarU->Scroll += gcnew System::EventHandler(this, &ToolWindow::OnTrackBarScroll);
			// 
			// trackBarV
			// 
			this->trackBarV->Location = System::Drawing::Point(40, 115);
			this->trackBarV->Maximum = 200;
			this->trackBarV->Name = L"trackBarV";
			this->trackBarV->Size = System::Drawing::Size(431, 45);
			this->trackBarV->TabIndex = 7;
			this->trackBarV->TickFrequency = 10;
			this->trackBarV->Value = 100;
			this->trackBarV->Scroll += gcnew System::EventHandler(this, &ToolWindow::OnTrackBarScroll);
			// 
			// labelY
			// 
			this->labelY->AutoSize = true;
			this->labelY->Location = System::Drawing::Point(10, 25);
			this->labelY->Name = L"labelY";
			this->labelY->Size = System::Drawing::Size(14, 13);
			this->labelY->TabIndex = 0;
			this->labelY->Text = L"Y";
			// 
			// labelU
			// 
			this->labelU->AutoSize = true;
			this->labelU->Location = System::Drawing::Point(10, 75);
			this->labelU->Name = L"labelU";
			this->labelU->Size = System::Drawing::Size(15, 13);
			this->labelU->TabIndex = 3;
			this->labelU->Text = L"U";
			// 
			// labelV
			// 
			this->labelV->AutoSize = true;
			this->labelV->Location = System::Drawing::Point(10, 125);
			this->labelV->Name = L"labelV";
			this->labelV->Size = System::Drawing::Size(14, 13);
			this->labelV->TabIndex = 6;
			this->labelV->Text = L"V";
			// 
			// labelYVal
			// 
			this->labelYVal->AutoSize = true;
			this->labelYVal->Location = System::Drawing::Point(477, 25);
			this->labelYVal->Name = L"labelYVal";
			this->labelYVal->Size = System::Drawing::Size(33, 13);
			this->labelYVal->TabIndex = 2;
			this->labelYVal->Text = L"100%";
			// 
			// labelUVal
			// 
			this->labelUVal->AutoSize = true;
			this->labelUVal->Location = System::Drawing::Point(477, 75);
			this->labelUVal->Name = L"labelUVal";
			this->labelUVal->Size = System::Drawing::Size(33, 13);
			this->labelUVal->TabIndex = 5;
			this->labelUVal->Text = L"100%";
			// 
			// labelVVal
			// 
			this->labelVVal->AutoSize = true;
			this->labelVVal->Location = System::Drawing::Point(477, 125);
			this->labelVVal->Name = L"labelVVal";
			this->labelVVal->Size = System::Drawing::Size(33, 13);
			this->labelVVal->TabIndex = 8;
			this->labelVVal->Text = L"100%";
			// 
			// checkBoxInvert
			// 
			this->checkBoxInvert->AutoSize = true;
			this->checkBoxInvert->Location = System::Drawing::Point(10, 165);
			this->checkBoxInvert->Name = L"checkBoxInvert";
			this->checkBoxInvert->Size = System::Drawing::Size(85, 17);
			this->checkBoxInvert->TabIndex = 9;
			this->checkBoxInvert->Text = L"Invert Colors";
			this->checkBoxInvert->UseVisualStyleBackColor = true;
			this->checkBoxInvert->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::OnInvertChecked);
			// 
			// ToolWindow
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(563, 205);
			this->Controls->Add(this->labelY);
			this->Controls->Add(this->trackBarY);
			this->Controls->Add(this->labelYVal);
			this->Controls->Add(this->labelU);
			this->Controls->Add(this->trackBarU);
			this->Controls->Add(this->labelUVal);
			this->Controls->Add(this->labelV);
			this->Controls->Add(this->trackBarV);
			this->Controls->Add(this->labelVVal);
			this->Controls->Add(this->checkBoxInvert);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ToolWindow";
			this->Text = L"Tool Box";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarU))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void OnTrackBarScroll(System::Object^ sender, System::EventArgs^ e)
	{
		UpdateValues();
	}

	private: System::Void OnInvertChecked(System::Object^ sender, System::EventArgs^ e)
	{
		UpdateValues();
	}

	private: void UpdateValues()
	{
		// read the UI and store to the static fields (scaled as percent ints, keep 0..200)
		YValue = (float)trackBarY->Value;
		UValue = (float)trackBarU->Value;
		VValue = (float)trackBarV->Value;
		InvertColors = checkBoxInvert->Checked;

		// update percent readouts as strings e.g. "135%"
		labelYVal->Text = System::String::Format("{0}%", trackBarY->Value);
		labelUVal->Text = System::String::Format("{0}%", trackBarU->Value);
		labelVVal->Text = System::String::Format("{0}%", trackBarV->Value);
	}
	};
} // namespace PrimitiveDrawTest