#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegExp>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	{
		ui->setupUi(this);
		connect(ui->lineEdit,&QLineEdit::textEdited,[this](QString currentText) {
				QRegularExpression exp ("^\\+\\d{11}$");
				if(exp.match(currentText).hasMatch())
					setOklabel();
				else
					setNonOklabel();
			});
	}

MainWindow::~MainWindow()
	{
		delete ui;
	}

void MainWindow::setOklabel()
	{
		ui->label->setText("OK")	;
		ui->label->setStyleSheet("QLabel{color:green;}");
	}

void MainWindow::setNonOklabel()
	{
		ui->label->setText("FAIL")	;
		ui->label->setStyleSheet("QLabel{color:red;}");
	}

