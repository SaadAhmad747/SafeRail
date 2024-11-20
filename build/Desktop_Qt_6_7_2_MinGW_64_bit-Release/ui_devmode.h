/********************************************************************************
** Form generated from reading UI file 'devmode.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVMODE_H
#define UI_DEVMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DevMode
{
public:
    QVBoxLayout *verticalLayout_4;
    QTabWidget *DevTab;
    QWidget *CameraTab;
    QGridLayout *gridLayout_2;
    QLabel *OpticalLabel;
    QLabel *ThermalLabel;
    QWidget *OpticFeed;
    QWidget *ThermalFeed;
    QLabel *FusedLabel;
    QWidget *FuseFeed;
    QWidget *RadarTab;
    QGridLayout *gridLayout_6;
    QVBoxLayout *VertPanel;
    QLabel *lSpeed_M_KM;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *RadarBtn;
    QLabel *RadarLabel;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QPushButton *LoadButton;
    QPushButton *NetworkButton;
    QGroupBox *gBClFilt;
    QGridLayout *gridLayout_4;
    QGridLayout *gridProps;
    QCheckBox *rRange;
    QCheckBox *rAngle;
    QCheckBox *rVelocity;
    QCheckBox *Arc;
    QGroupBox *gBClObjType;
    QGridLayout *gridLayout_3;
    QGridLayout *gridTypes;
    QToolButton *OffTrackTBtn;
    QToolButton *OnTrackTBtn;
    QLabel *OffTrackLabel;
    QLabel *OnTrackLabel;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *RedLabel;
    QLabel *BlueLabel;
    QLabel *BlueColor;
    QLabel *RedColor;
    QVBoxLayout *verticalLayout;
    QScrollArea *sAVisual;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lZoom;
    QSlider *hSZoom;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DevMode)
    {
        if (DevMode->objectName().isEmpty())
            DevMode->setObjectName("DevMode");
        DevMode->resize(1180, 896);
        verticalLayout_4 = new QVBoxLayout(DevMode);
        verticalLayout_4->setObjectName("verticalLayout_4");
        DevTab = new QTabWidget(DevMode);
        DevTab->setObjectName("DevTab");
        QFont font;
        font.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        DevTab->setFont(font);
        CameraTab = new QWidget();
        CameraTab->setObjectName("CameraTab");
        gridLayout_2 = new QGridLayout(CameraTab);
        gridLayout_2->setObjectName("gridLayout_2");
        OpticalLabel = new QLabel(CameraTab);
        OpticalLabel->setObjectName("OpticalLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OpticalLabel->sizePolicy().hasHeightForWidth());
        OpticalLabel->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        font1.setPointSize(10);
        font1.setBold(true);
        OpticalLabel->setFont(font1);
        OpticalLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(OpticalLabel, 0, 0, 1, 1, Qt::AlignmentFlag::AlignRight);

        ThermalLabel = new QLabel(CameraTab);
        ThermalLabel->setObjectName("ThermalLabel");
        sizePolicy.setHeightForWidth(ThermalLabel->sizePolicy().hasHeightForWidth());
        ThermalLabel->setSizePolicy(sizePolicy);
        ThermalLabel->setFont(font1);
        ThermalLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(ThermalLabel, 0, 3, 1, 1, Qt::AlignmentFlag::AlignLeft);

        OpticFeed = new QWidget(CameraTab);
        OpticFeed->setObjectName("OpticFeed");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(OpticFeed->sizePolicy().hasHeightForWidth());
        OpticFeed->setSizePolicy(sizePolicy1);
        OpticFeed->setMaximumSize(QSize(700, 16777215));
        QFont font2;
        font2.setBold(true);
        OpticFeed->setFont(font2);
        OpticFeed->setStyleSheet(QString::fromUtf8("Background-color:rgb(0, 0, 0)"));

        gridLayout_2->addWidget(OpticFeed, 1, 0, 1, 2);

        ThermalFeed = new QWidget(CameraTab);
        ThermalFeed->setObjectName("ThermalFeed");
        sizePolicy1.setHeightForWidth(ThermalFeed->sizePolicy().hasHeightForWidth());
        ThermalFeed->setSizePolicy(sizePolicy1);
        ThermalFeed->setMaximumSize(QSize(700, 16777215));
        ThermalFeed->setStyleSheet(QString::fromUtf8("Background-color:rgb(0, 0, 0)"));

        gridLayout_2->addWidget(ThermalFeed, 1, 2, 1, 2);

        FusedLabel = new QLabel(CameraTab);
        FusedLabel->setObjectName("FusedLabel");
        sizePolicy.setHeightForWidth(FusedLabel->sizePolicy().hasHeightForWidth());
        FusedLabel->setSizePolicy(sizePolicy);
        FusedLabel->setFont(font1);
        FusedLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(FusedLabel, 2, 1, 1, 2);

        FuseFeed = new QWidget(CameraTab);
        FuseFeed->setObjectName("FuseFeed");
        sizePolicy1.setHeightForWidth(FuseFeed->sizePolicy().hasHeightForWidth());
        FuseFeed->setSizePolicy(sizePolicy1);
        FuseFeed->setMinimumSize(QSize(700, 0));
        FuseFeed->setMaximumSize(QSize(700, 16777215));
        FuseFeed->setStyleSheet(QString::fromUtf8("Background-color:rgb(0, 0, 0)"));

        gridLayout_2->addWidget(FuseFeed, 3, 0, 1, 4, Qt::AlignmentFlag::AlignHCenter);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 4);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setRowStretch(3, 4);
        DevTab->addTab(CameraTab, QString());
        RadarTab = new QWidget();
        RadarTab->setObjectName("RadarTab");
        gridLayout_6 = new QGridLayout(RadarTab);
        gridLayout_6->setObjectName("gridLayout_6");
        VertPanel = new QVBoxLayout();
        VertPanel->setObjectName("VertPanel");
        lSpeed_M_KM = new QLabel(RadarTab);
        lSpeed_M_KM->setObjectName("lSpeed_M_KM");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lSpeed_M_KM->sizePolicy().hasHeightForWidth());
        lSpeed_M_KM->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        font3.setPointSize(12);
        font3.setBold(true);
        lSpeed_M_KM->setFont(font3);
        lSpeed_M_KM->setAlignment(Qt::AlignmentFlag::AlignCenter);

        VertPanel->addWidget(lSpeed_M_KM);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        RadarBtn = new QPushButton(RadarTab);
        RadarBtn->setObjectName("RadarBtn");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(RadarBtn->sizePolicy().hasHeightForWidth());
        RadarBtn->setSizePolicy(sizePolicy3);
        RadarBtn->setMinimumSize(QSize(0, 10));
        RadarBtn->setMaximumSize(QSize(200, 16777215));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        font4.setPointSize(11);
        font4.setBold(true);
        RadarBtn->setFont(font4);

        horizontalLayout_4->addWidget(RadarBtn);

        RadarLabel = new QLabel(RadarTab);
        RadarLabel->setObjectName("RadarLabel");
        sizePolicy.setHeightForWidth(RadarLabel->sizePolicy().hasHeightForWidth());
        RadarLabel->setSizePolicy(sizePolicy);
        RadarLabel->setMinimumSize(QSize(0, 0));
        RadarLabel->setFont(font3);
        RadarLabel->setStyleSheet(QString::fromUtf8("Background-color:red"));
        RadarLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(RadarLabel);


        VertPanel->addLayout(horizontalLayout_4);

        groupBox = new QGroupBox(RadarTab);
        groupBox->setObjectName("groupBox");
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName("gridLayout_5");
        LoadButton = new QPushButton(groupBox);
        LoadButton->setObjectName("LoadButton");

        gridLayout_5->addWidget(LoadButton, 0, 1, 1, 1);

        NetworkButton = new QPushButton(groupBox);
        NetworkButton->setObjectName("NetworkButton");

        gridLayout_5->addWidget(NetworkButton, 0, 0, 1, 1);


        VertPanel->addWidget(groupBox);

        gBClFilt = new QGroupBox(RadarTab);
        gBClFilt->setObjectName("gBClFilt");
        sizePolicy.setHeightForWidth(gBClFilt->sizePolicy().hasHeightForWidth());
        gBClFilt->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(gBClFilt);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridProps = new QGridLayout();
        gridProps->setSpacing(0);
        gridProps->setObjectName("gridProps");
        rRange = new QCheckBox(gBClFilt);
        rRange->setObjectName("rRange");
        rRange->setChecked(true);

        gridProps->addWidget(rRange, 0, 0, 1, 1);

        rAngle = new QCheckBox(gBClFilt);
        rAngle->setObjectName("rAngle");
        rAngle->setMouseTracking(true);
        rAngle->setToolTipDuration(-1);
        rAngle->setChecked(false);

        gridProps->addWidget(rAngle, 1, 0, 1, 1);

        rVelocity = new QCheckBox(gBClFilt);
        rVelocity->setObjectName("rVelocity");

        gridProps->addWidget(rVelocity, 2, 0, 1, 1);

        Arc = new QCheckBox(gBClFilt);
        Arc->setObjectName("Arc");
        Arc->setChecked(true);

        gridProps->addWidget(Arc, 3, 0, 1, 1);


        gridLayout_4->addLayout(gridProps, 0, 0, 1, 1);


        VertPanel->addWidget(gBClFilt);

        gBClObjType = new QGroupBox(RadarTab);
        gBClObjType->setObjectName("gBClObjType");
        sizePolicy.setHeightForWidth(gBClObjType->sizePolicy().hasHeightForWidth());
        gBClObjType->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(gBClObjType);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridTypes = new QGridLayout();
        gridTypes->setObjectName("gridTypes");
        gridTypes->setVerticalSpacing(4);
        OffTrackTBtn = new QToolButton(gBClObjType);
        OffTrackTBtn->setObjectName("OffTrackTBtn");
        OffTrackTBtn->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 0)"));

        gridTypes->addWidget(OffTrackTBtn, 0, 0, 1, 1);

        OnTrackTBtn = new QToolButton(gBClObjType);
        OnTrackTBtn->setObjectName("OnTrackTBtn");
        OnTrackTBtn->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 0, 0)"));

        gridTypes->addWidget(OnTrackTBtn, 1, 0, 1, 1);

        OffTrackLabel = new QLabel(gBClObjType);
        OffTrackLabel->setObjectName("OffTrackLabel");

        gridTypes->addWidget(OffTrackLabel, 0, 1, 1, 1);

        OnTrackLabel = new QLabel(gBClObjType);
        OnTrackLabel->setObjectName("OnTrackLabel");

        gridTypes->addWidget(OnTrackLabel, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridTypes, 0, 0, 1, 1);


        VertPanel->addWidget(gBClObjType);

        groupBox_2 = new QGroupBox(RadarTab);
        groupBox_2->setObjectName("groupBox_2");
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName("gridLayout");
        RedLabel = new QLabel(groupBox_2);
        RedLabel->setObjectName("RedLabel");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(RedLabel->sizePolicy().hasHeightForWidth());
        RedLabel->setSizePolicy(sizePolicy4);
        RedLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(RedLabel, 0, 0, 1, 1);

        BlueLabel = new QLabel(groupBox_2);
        BlueLabel->setObjectName("BlueLabel");
        sizePolicy4.setHeightForWidth(BlueLabel->sizePolicy().hasHeightForWidth());
        BlueLabel->setSizePolicy(sizePolicy4);
        BlueLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(BlueLabel, 1, 0, 1, 1);

        BlueColor = new QLabel(groupBox_2);
        BlueColor->setObjectName("BlueColor");
        sizePolicy4.setHeightForWidth(BlueColor->sizePolicy().hasHeightForWidth());
        BlueColor->setSizePolicy(sizePolicy4);
        BlueColor->setStyleSheet(QString::fromUtf8("Background-color:rgb(160, 210, 255)"));

        gridLayout->addWidget(BlueColor, 0, 1, 1, 1);

        RedColor = new QLabel(groupBox_2);
        RedColor->setObjectName("RedColor");
        sizePolicy4.setHeightForWidth(RedColor->sizePolicy().hasHeightForWidth());
        RedColor->setSizePolicy(sizePolicy4);
        RedColor->setStyleSheet(QString::fromUtf8("Background-color:rgb(255, 200, 200)"));

        gridLayout->addWidget(RedColor, 1, 1, 1, 1);


        VertPanel->addWidget(groupBox_2);


        gridLayout_6->addLayout(VertPanel, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        sAVisual = new QScrollArea(RadarTab);
        sAVisual->setObjectName("sAVisual");
        sAVisual->setMouseTracking(true);
        sAVisual->setWidgetResizable(true);
        sAVisual->setAlignment(Qt::AlignmentFlag::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 924, 789));
        sAVisual->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(sAVisual);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lZoom = new QLabel(RadarTab);
        lZoom->setObjectName("lZoom");

        horizontalLayout_2->addWidget(lZoom);

        hSZoom = new QSlider(RadarTab);
        hSZoom->setObjectName("hSZoom");
        hSZoom->setMinimum(400);
        hSZoom->setMaximum(2000);
        hSZoom->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(hSZoom);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_6->addLayout(verticalLayout, 0, 1, 2, 1);

        verticalSpacer = new QSpacerItem(20, 310, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 1, 0, 1, 1);

        gridLayout_6->setColumnStretch(0, 1);
        gridLayout_6->setColumnStretch(1, 9);
        DevTab->addTab(RadarTab, QString());

        verticalLayout_4->addWidget(DevTab);


        retranslateUi(DevMode);

        DevTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DevMode);
    } // setupUi

    void retranslateUi(QWidget *DevMode)
    {
        DevMode->setWindowTitle(QCoreApplication::translate("DevMode", "Form", nullptr));
        OpticalLabel->setText(QCoreApplication::translate("DevMode", "Optical", nullptr));
        ThermalLabel->setText(QCoreApplication::translate("DevMode", "Thermal", nullptr));
        FusedLabel->setText(QCoreApplication::translate("DevMode", "Fused", nullptr));
        DevTab->setTabText(DevTab->indexOf(CameraTab), QCoreApplication::translate("DevMode", "Camera Feeds", nullptr));
        lSpeed_M_KM->setText(QCoreApplication::translate("DevMode", "Config Radar", nullptr));
        RadarBtn->setText(QCoreApplication::translate("DevMode", "Power", nullptr));
        RadarLabel->setText(QCoreApplication::translate("DevMode", "Off", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DevMode", "Source:", nullptr));
        LoadButton->setText(QCoreApplication::translate("DevMode", "Log File", nullptr));
        NetworkButton->setText(QCoreApplication::translate("DevMode", "Network", nullptr));
        gBClFilt->setTitle(QCoreApplication::translate("DevMode", "Display filter (postproc):", nullptr));
        rRange->setText(QCoreApplication::translate("DevMode", "Range", nullptr));
#if QT_CONFIG(tooltip)
        rAngle->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rAngle->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        rAngle->setText(QCoreApplication::translate("DevMode", "Angle", nullptr));
        rVelocity->setText(QCoreApplication::translate("DevMode", "Velocity", nullptr));
        Arc->setText(QCoreApplication::translate("DevMode", "Arc", nullptr));
        gBClObjType->setTitle(QCoreApplication::translate("DevMode", "Cluster/Object type:", nullptr));
        OffTrackTBtn->setText(QString());
        OnTrackTBtn->setText(QString());
        OffTrackLabel->setText(QCoreApplication::translate("DevMode", "Off-Track", nullptr));
        OnTrackLabel->setText(QCoreApplication::translate("DevMode", "On-Track", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DevMode", "Range:", nullptr));
        RedLabel->setText(QCoreApplication::translate("DevMode", "Max Coverage", nullptr));
        BlueLabel->setText(QCoreApplication::translate("DevMode", "Brake Distance", nullptr));
        BlueColor->setText(QString());
        RedColor->setText(QString());
        lZoom->setText(QCoreApplication::translate("DevMode", "Zoom", nullptr));
        DevTab->setTabText(DevTab->indexOf(RadarTab), QCoreApplication::translate("DevMode", "Radar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DevMode: public Ui_DevMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVMODE_H
