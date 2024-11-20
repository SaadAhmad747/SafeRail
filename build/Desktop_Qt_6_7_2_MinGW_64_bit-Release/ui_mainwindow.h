/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *MainMenu;
    QVBoxLayout *verticalLayout_4;
    QLabel *MainLabel;
    QWidget *MainBtnBox;
    QVBoxLayout *verticalLayout_3;
    QPushButton *BtnConnect;
    QPushButton *BtnDevmode;
    QPushButton *BtnSettings;
    QWidget *SettingTab;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *SettingsTabWidget;
    QWidget *CameraSetting;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *CIpLabel;
    QLineEdit *CameraIp;
    QLabel *CIdLabel;
    QLineEdit *CameraId;
    QLabel *CPassLabel;
    QLineEdit *CameraPass;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLabel *JSIpLabel;
    QLineEdit *JetsonIp;
    QLabel *JSPortLabel;
    QLineEdit *JetsonPort;
    QWidget *RadarSetting;
    QLabel *VelocityLabel;
    QLabel *AngleLabel;
    QDoubleSpinBox *AngleDS;
    QComboBox *ProfileCBox;
    QLabel *ProfileLabel;
    QGroupBox *RangeGBox;
    QLabel *MiniLabel;
    QLabel *UnamLabel;
    QDoubleSpinBox *MiniRangeDS;
    QDoubleSpinBox *UnamRangeDS;
    QLabel *MaxLabel;
    QDoubleSpinBox *MaxRangeDS;
    QDoubleSpinBox *VelocityDS;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_3;
    QLabel *RSIpLabel;
    QLineEdit *RadarIP;
    QLabel *RSPortLabel;
    QLineEdit *RadarPort;
    QWidget *ButtonBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *BtnSave;
    QPushButton *BtnBack;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1114, 602);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QFont font;
        font.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        centralwidget->setFont(font);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        font1.setBold(true);
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("        QTabWidget::tab-bar {\n"
"            alignment: center;\n"
"        }"));
        MainMenu = new QWidget();
        MainMenu->setObjectName("MainMenu");
        MainMenu->setFont(font);
        verticalLayout_4 = new QVBoxLayout(MainMenu);
        verticalLayout_4->setObjectName("verticalLayout_4");
        MainLabel = new QLabel(MainMenu);
        MainLabel->setObjectName("MainLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(MainLabel->sizePolicy().hasHeightForWidth());
        MainLabel->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        font2.setPointSize(72);
        MainLabel->setFont(font2);
        MainLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(MainLabel);

        MainBtnBox = new QWidget(MainMenu);
        MainBtnBox->setObjectName("MainBtnBox");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(MainBtnBox->sizePolicy().hasHeightForWidth());
        MainBtnBox->setSizePolicy(sizePolicy2);
        MainBtnBox->setMinimumSize(QSize(1000, 250));
        MainBtnBox->setMaximumSize(QSize(1000, 1000));
        verticalLayout_3 = new QVBoxLayout(MainBtnBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        BtnConnect = new QPushButton(MainBtnBox);
        BtnConnect->setObjectName("BtnConnect");
        sizePolicy.setHeightForWidth(BtnConnect->sizePolicy().hasHeightForWidth());
        BtnConnect->setSizePolicy(sizePolicy);
        BtnConnect->setMinimumSize(QSize(280, 90));
        BtnConnect->setMaximumSize(QSize(280, 90));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setStrikeOut(false);
        BtnConnect->setFont(font3);
        BtnConnect->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        BtnConnect->setAutoFillBackground(false);
        BtnConnect->setStyleSheet(QString::fromUtf8("     QPushButton {\n"
"         background-color: #5cb85c;\n"
"         color: white;\n"
"         font-weight: bold;\n"
"         border-radius: 8px;\n"
"     }\n"
"     QPushButton:hover {\n"
"         color: black;\n"
"     }"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/connection.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BtnConnect->setIcon(icon);
        BtnConnect->setIconSize(QSize(25, 25));

        verticalLayout_3->addWidget(BtnConnect, 0, Qt::AlignmentFlag::AlignHCenter);

        BtnDevmode = new QPushButton(MainBtnBox);
        BtnDevmode->setObjectName("BtnDevmode");
        sizePolicy.setHeightForWidth(BtnDevmode->sizePolicy().hasHeightForWidth());
        BtnDevmode->setSizePolicy(sizePolicy);
        BtnDevmode->setMinimumSize(QSize(280, 90));
        BtnDevmode->setMaximumSize(QSize(280, 90));
        BtnDevmode->setFont(font3);
        BtnDevmode->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        BtnDevmode->setAutoFillBackground(false);
        BtnDevmode->setStyleSheet(QString::fromUtf8("     QPushButton {\n"
"         background-color: #6F42C1;\n"
"         color: white;\n"
"         font-weight: bold;\n"
"         border-radius: 8px;\n"
"     }\n"
"     QPushButton:hover {\n"
"         color: black;\n"
"     }"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/dev.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BtnDevmode->setIcon(icon1);
        BtnDevmode->setIconSize(QSize(25, 25));
        BtnDevmode->setCheckable(false);
        BtnDevmode->setAutoRepeat(false);

        verticalLayout_3->addWidget(BtnDevmode, 0, Qt::AlignmentFlag::AlignHCenter);

        BtnSettings = new QPushButton(MainBtnBox);
        BtnSettings->setObjectName("BtnSettings");
        sizePolicy.setHeightForWidth(BtnSettings->sizePolicy().hasHeightForWidth());
        BtnSettings->setSizePolicy(sizePolicy);
        BtnSettings->setMinimumSize(QSize(250, 80));
        BtnSettings->setMaximumSize(QSize(250, 80));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        font4.setPointSize(14);
        font4.setBold(true);
        BtnSettings->setFont(font4);
        BtnSettings->setStyleSheet(QString::fromUtf8("     QPushButton {\n"
"         background-color: #0055ff;\n"
"         color: white;\n"
"         font-weight: bold;\n"
"         border-radius: 8px;\n"
"     }\n"
"     QPushButton:hover {\n"
"         color: black;\n"
"     }"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/gear.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BtnSettings->setIcon(icon2);
        BtnSettings->setIconSize(QSize(25, 25));

        verticalLayout_3->addWidget(BtnSettings, 0, Qt::AlignmentFlag::AlignHCenter);


        verticalLayout_4->addWidget(MainBtnBox, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        tabWidget->addTab(MainMenu, QString());
        SettingTab = new QWidget();
        SettingTab->setObjectName("SettingTab");
        SettingTab->setFont(font);
        SettingTab->setStyleSheet(QString::fromUtf8("        QTabWidget::tab-bar {\n"
"            alignment: left;\n"
"        }"));
        verticalLayout_2 = new QVBoxLayout(SettingTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        SettingsTabWidget = new QTabWidget(SettingTab);
        SettingsTabWidget->setObjectName("SettingsTabWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(100);
        sizePolicy3.setHeightForWidth(SettingsTabWidget->sizePolicy().hasHeightForWidth());
        SettingsTabWidget->setSizePolicy(sizePolicy3);
        SettingsTabWidget->setMaximumSize(QSize(16777215, 16777215));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        font5.setPointSize(12);
        SettingsTabWidget->setFont(font5);
        SettingsTabWidget->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
        CameraSetting = new QWidget();
        CameraSetting->setObjectName("CameraSetting");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(CameraSetting->sizePolicy().hasHeightForWidth());
        CameraSetting->setSizePolicy(sizePolicy4);
        CameraSetting->setMaximumSize(QSize(16777215, 16777215));
        layoutWidget = new QWidget(CameraSetting);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(11, 89, 361, 111));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        CIpLabel = new QLabel(layoutWidget);
        CIpLabel->setObjectName("CIpLabel");
        CIpLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, CIpLabel);

        CameraIp = new QLineEdit(layoutWidget);
        CameraIp->setObjectName("CameraIp");
        CameraIp->setMaximumSize(QSize(16777215, 16777215));
        CameraIp->setFont(font);
        CameraIp->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        CameraIp->setStyleSheet(QString::fromUtf8("QLineEdit:hover {\n"
"    border: 2px solid;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, CameraIp);

        CIdLabel = new QLabel(layoutWidget);
        CIdLabel->setObjectName("CIdLabel");
        CIdLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, CIdLabel);

        CameraId = new QLineEdit(layoutWidget);
        CameraId->setObjectName("CameraId");
        CameraId->setMaximumSize(QSize(16777215, 16777215));
        CameraId->setFont(font);
        CameraId->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        CameraId->setStyleSheet(QString::fromUtf8("QLineEdit:hover {\n"
"    border: 2px solid;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, CameraId);

        CPassLabel = new QLabel(layoutWidget);
        CPassLabel->setObjectName("CPassLabel");
        CPassLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, CPassLabel);

        CameraPass = new QLineEdit(layoutWidget);
        CameraPass->setObjectName("CameraPass");
        CameraPass->setMaximumSize(QSize(16777215, 16777215));
        CameraPass->setFont(font);
        CameraPass->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        CameraPass->setStyleSheet(QString::fromUtf8("QLineEdit:hover {\n"
"    border: 2px solid;\n"
"}"));
        CameraPass->setEchoMode(QLineEdit::EchoMode::Normal);

        formLayout->setWidget(2, QFormLayout::FieldRole, CameraPass);

        groupBox = new QGroupBox(CameraSetting);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 210, 361, 111));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setObjectName("formLayout_2");
        JSIpLabel = new QLabel(groupBox);
        JSIpLabel->setObjectName("JSIpLabel");
        JSIpLabel->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, JSIpLabel);

        JetsonIp = new QLineEdit(groupBox);
        JetsonIp->setObjectName("JetsonIp");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(JetsonIp->sizePolicy().hasHeightForWidth());
        JetsonIp->setSizePolicy(sizePolicy5);
        JetsonIp->setMaximumSize(QSize(16777215, 16777215));
        JetsonIp->setFont(font);
        JetsonIp->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        JetsonIp->setStyleSheet(QString::fromUtf8("QLineEdit:hover {\n"
"    border: 2px solid;\n"
"}"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, JetsonIp);

        JSPortLabel = new QLabel(groupBox);
        JSPortLabel->setObjectName("JSPortLabel");
        JSPortLabel->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, JSPortLabel);

        JetsonPort = new QLineEdit(groupBox);
        JetsonPort->setObjectName("JetsonPort");
        JetsonPort->setMaximumSize(QSize(16777215, 16777215));
        JetsonPort->setFont(font);
        JetsonPort->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        JetsonPort->setStyleSheet(QString::fromUtf8("QLineEdit:hover {\n"
"    border: 2px solid;\n"
"}"));
        JetsonPort->setMaxLength(32767);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, JetsonPort);

        SettingsTabWidget->addTab(CameraSetting, QString());
        RadarSetting = new QWidget();
        RadarSetting->setObjectName("RadarSetting");
        VelocityLabel = new QLabel(RadarSetting);
        VelocityLabel->setObjectName("VelocityLabel");
        VelocityLabel->setGeometry(QRect(60, 260, 91, 31));
        VelocityLabel->setFont(font);
        AngleLabel = new QLabel(RadarSetting);
        AngleLabel->setObjectName("AngleLabel");
        AngleLabel->setGeometry(QRect(60, 300, 91, 31));
        AngleLabel->setFont(font);
        AngleDS = new QDoubleSpinBox(RadarSetting);
        AngleDS->setObjectName("AngleDS");
        AngleDS->setGeometry(QRect(150, 300, 81, 29));
        AngleDS->setMaximum(9999.989999999999782);
        ProfileCBox = new QComboBox(RadarSetting);
        ProfileCBox->addItem(QString());
        ProfileCBox->addItem(QString());
        ProfileCBox->setObjectName("ProfileCBox");
        ProfileCBox->setGeometry(QRect(70, 10, 101, 28));
        ProfileLabel = new QLabel(RadarSetting);
        ProfileLabel->setObjectName("ProfileLabel");
        ProfileLabel->setGeometry(QRect(10, 10, 63, 31));
        ProfileLabel->setFont(font);
        RangeGBox = new QGroupBox(RadarSetting);
        RangeGBox->setObjectName("RangeGBox");
        RangeGBox->setGeometry(QRect(30, 50, 271, 191));
        MiniLabel = new QLabel(RangeGBox);
        MiniLabel->setObjectName("MiniLabel");
        MiniLabel->setGeometry(QRect(30, 30, 71, 31));
        MiniLabel->setFont(font);
        UnamLabel = new QLabel(RangeGBox);
        UnamLabel->setObjectName("UnamLabel");
        UnamLabel->setGeometry(QRect(30, 80, 101, 31));
        UnamLabel->setFont(font);
        MiniRangeDS = new QDoubleSpinBox(RangeGBox);
        MiniRangeDS->setObjectName("MiniRangeDS");
        MiniRangeDS->setGeometry(QRect(140, 30, 81, 29));
        MiniRangeDS->setMaximum(9999.989999999999782);
        UnamRangeDS = new QDoubleSpinBox(RangeGBox);
        UnamRangeDS->setObjectName("UnamRangeDS");
        UnamRangeDS->setGeometry(QRect(140, 80, 81, 29));
        UnamRangeDS->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::UpDownArrows);
        UnamRangeDS->setMaximum(9999.989999999999782);
        MaxLabel = new QLabel(RangeGBox);
        MaxLabel->setObjectName("MaxLabel");
        MaxLabel->setGeometry(QRect(30, 130, 71, 31));
        MaxLabel->setFont(font);
        MaxRangeDS = new QDoubleSpinBox(RangeGBox);
        MaxRangeDS->setObjectName("MaxRangeDS");
        MaxRangeDS->setGeometry(QRect(140, 130, 81, 29));
        MaxRangeDS->setMaximum(9999.989999999999782);
        VelocityDS = new QDoubleSpinBox(RadarSetting);
        VelocityDS->setObjectName("VelocityDS");
        VelocityDS->setGeometry(QRect(150, 260, 81, 29));
        VelocityDS->setMaximum(9999.989999999999782);
        groupBox_2 = new QGroupBox(RadarSetting);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(320, 60, 221, 111));
        formLayout_3 = new QFormLayout(groupBox_2);
        formLayout_3->setObjectName("formLayout_3");
        RSIpLabel = new QLabel(groupBox_2);
        RSIpLabel->setObjectName("RSIpLabel");
        RSIpLabel->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, RSIpLabel);

        RadarIP = new QLineEdit(groupBox_2);
        RadarIP->setObjectName("RadarIP");
        sizePolicy5.setHeightForWidth(RadarIP->sizePolicy().hasHeightForWidth());
        RadarIP->setSizePolicy(sizePolicy5);
        RadarIP->setMaximumSize(QSize(16777215, 16777215));
        RadarIP->setFont(font);
        RadarIP->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        RadarIP->setStyleSheet(QString::fromUtf8("QLineEdit:hover {\n"
"    border: 2px solid;\n"
"}"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, RadarIP);

        RSPortLabel = new QLabel(groupBox_2);
        RSPortLabel->setObjectName("RSPortLabel");
        RSPortLabel->setFont(font);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, RSPortLabel);

        RadarPort = new QLineEdit(groupBox_2);
        RadarPort->setObjectName("RadarPort");
        RadarPort->setMaximumSize(QSize(16777215, 16777215));
        RadarPort->setFont(font);
        RadarPort->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        RadarPort->setStyleSheet(QString::fromUtf8("QLineEdit:hover {\n"
"    border: 2px solid;\n"
"}"));
        RadarPort->setMaxLength(32767);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, RadarPort);

        SettingsTabWidget->addTab(RadarSetting, QString());

        verticalLayout_2->addWidget(SettingsTabWidget);

        ButtonBox = new QWidget(SettingTab);
        ButtonBox->setObjectName("ButtonBox");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(8);
        sizePolicy6.setHeightForWidth(ButtonBox->sizePolicy().hasHeightForWidth());
        ButtonBox->setSizePolicy(sizePolicy6);
        horizontalLayout = new QHBoxLayout(ButtonBox);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        BtnSave = new QPushButton(ButtonBox);
        BtnSave->setObjectName("BtnSave");
        sizePolicy.setHeightForWidth(BtnSave->sizePolicy().hasHeightForWidth());
        BtnSave->setSizePolicy(sizePolicy);
        BtnSave->setMinimumSize(QSize(280, 50));
        BtnSave->setMaximumSize(QSize(280, 90));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setStrikeOut(false);
        BtnSave->setFont(font6);
        BtnSave->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        BtnSave->setAutoFillBackground(false);
        BtnSave->setStyleSheet(QString::fromUtf8("     QPushButton {\n"
"         background-color: rgb(99, 99, 99);\n"
"         color: lightgray;\n"
"         font-weight: bold;\n"
"         border-radius: 8px;\n"
"     }\n"
"	QPushButton:enabled{\n"
"	     background-color: #5cb85c;\n"
"         color: white;\n"
"         font-weight: bold;\n"
"         border-radius: 8px;\n"
"}\n"
"     QPushButton:hover {\n"
"         color: black;\n"
"     }"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        BtnSave->setIcon(icon3);
        BtnSave->setIconSize(QSize(20, 20));
        BtnSave->setFlat(false);

        horizontalLayout->addWidget(BtnSave);

        BtnBack = new QPushButton(ButtonBox);
        BtnBack->setObjectName("BtnBack");
        sizePolicy4.setHeightForWidth(BtnBack->sizePolicy().hasHeightForWidth());
        BtnBack->setSizePolicy(sizePolicy4);
        BtnBack->setMinimumSize(QSize(250, 50));
        BtnBack->setMaximumSize(QSize(250, 200));
        BtnBack->setFont(font1);
        BtnBack->setStyleSheet(QString::fromUtf8("     QPushButton {\n"
"         background-color: #0055ff;\n"
"         color: white;\n"
"         font-size: 16px;\n"
"         font-weight: bold;\n"
"         border-radius: 8px;\n"
"     }\n"
"     QPushButton:hover {\n"
"         color: black;\n"
"     }"));
        BtnBack->setIconSize(QSize(20, 20));
        BtnBack->setCheckable(false);

        horizontalLayout->addWidget(BtnBack);


        verticalLayout_2->addWidget(ButtonBox);

        tabWidget->addTab(SettingTab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        SettingsTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "RailwayMMI", nullptr));
        MainLabel->setText(QCoreApplication::translate("MainWindow", "SAFERAIL", nullptr));
        BtnConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        BtnDevmode->setText(QCoreApplication::translate("MainWindow", "Dev Mode", nullptr));
        BtnSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(MainMenu), QCoreApplication::translate("MainWindow", "Main Menu", nullptr));
        CIpLabel->setText(QCoreApplication::translate("MainWindow", "Camera IP", nullptr));
        CIdLabel->setText(QCoreApplication::translate("MainWindow", "Camera ID/User", nullptr));
        CPassLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Jetson", nullptr));
        JSIpLabel->setText(QCoreApplication::translate("MainWindow", "Server IP", nullptr));
        JSPortLabel->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        JetsonPort->setInputMask(QString());
        SettingsTabWidget->setTabText(SettingsTabWidget->indexOf(CameraSetting), QCoreApplication::translate("MainWindow", "Camera", nullptr));
        VelocityLabel->setText(QCoreApplication::translate("MainWindow", "Velocity, m/s", nullptr));
        AngleLabel->setText(QCoreApplication::translate("MainWindow", "Angle, deg", nullptr));
        ProfileCBox->setItemText(0, QCoreApplication::translate("MainWindow", "Profile 1", nullptr));
        ProfileCBox->setItemText(1, QCoreApplication::translate("MainWindow", "Profile 2", nullptr));

        ProfileLabel->setText(QCoreApplication::translate("MainWindow", "Profiles:", nullptr));
        RangeGBox->setTitle(QCoreApplication::translate("MainWindow", "Range, m", nullptr));
        MiniLabel->setText(QCoreApplication::translate("MainWindow", "Minimum", nullptr));
        UnamLabel->setText(QCoreApplication::translate("MainWindow", "Unambiguous", nullptr));
        MaxLabel->setText(QCoreApplication::translate("MainWindow", "Maximum", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Radar Server ", nullptr));
        RSIpLabel->setText(QCoreApplication::translate("MainWindow", "IP", nullptr));
        RSPortLabel->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        RadarPort->setInputMask(QString());
        SettingsTabWidget->setTabText(SettingsTabWidget->indexOf(RadarSetting), QCoreApplication::translate("MainWindow", "Radar", nullptr));
        BtnSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        BtnBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SettingTab), QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
