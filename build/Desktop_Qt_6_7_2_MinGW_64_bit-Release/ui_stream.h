/********************************************************************************
** Form generated from reading UI file 'stream.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STREAM_H
#define UI_STREAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stream
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *Fused;
    QGridLayout *gridLayout_4;
    QWidget *FusedVideoWidget;
    QWidget *Optical;
    QGridLayout *gridLayout_2;
    QWidget *OpticalVideoWidget;
    QWidget *Thermal;
    QGridLayout *gridLayout;
    QWidget *ThermalVideoWidget;
    QVBoxLayout *savisual;
    QLabel *RadarHLabel;
    QWidget *RadarStatusArea;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *RedLabel;
    QLabel *BlueLabel;
    QLabel *BlueColor;
    QLabel *RedColor;
    QGroupBox *gBClObjType;
    QGridLayout *gridLayout_5;
    QToolButton *OffTrackTBtn;
    QLabel *OffTrackLabel;
    QToolButton *OnTrackTBtn;
    QLabel *OnTrackLabel;
    QGroupBox *RadarStatus;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *RadarBtn;
    QLabel *RadarLabel;

    void setupUi(QWidget *Stream)
    {
        if (Stream->objectName().isEmpty())
            Stream->setObjectName("Stream");
        Stream->resize(934, 640);
        QFont font;
        font.setFamilies({QString::fromUtf8("Nirmala UI Semilight")});
        Stream->setFont(font);
        Stream->setStyleSheet(QString::fromUtf8("    QRadioButton {\n"
"        font-size: 14px;\n"
"        padding: 5px;\n"
"    }\n"
"    QRadioButton::indicator {\n"
"        width: 16px;\n"
"        height: 16px;\n"
"    }\n"
"    QRadioButton::indicator:checked {\n"
"        background-color: #2196F3;\n"
"        border-radius: 8px;\n"
"    }\n"
"    QRadioButton::indicator:unchecked {\n"
"        background-color: #d3d3d3;\n"
"        border-radius: 8px;\n"
"    }\n"
"   "));
        horizontalLayout = new QHBoxLayout(Stream);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(Stream);
        tabWidget->setObjectName("tabWidget");
        QFont font1;
        font1.setPointSize(28);
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
"        QTabWidget::pane {\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 4px;\n"
"            background: #f9f9f9;\n"
"        }\n"
"\n"
"        QTabWidget::tab-bar {\n"
"            alignment: center;\n"
"        }\n"
"\n"
"        QTabBar::tab {\n"
"			height:50px;\n"
"			width:200px;\n"
"            background: #e0e0e0;\n"
"            border: 1px solid #ccc;\n"
"            padding: 5px;\n"
"            margin: 2px;\n"
"            border-radius: 4px;\n"
"        }\n"
"\n"
"        QTabBar::tab:selected {\n"
"            background: #ffffff;\n"
"            border-bottom: 2px solid #007bff;\n"
"        }\n"
"\n"
"        QTabBar::tab:hover {\n"
"            background: #d0d0d0; \n"
"        }\n"
"       "));
        Fused = new QWidget();
        Fused->setObjectName("Fused");
        gridLayout_4 = new QGridLayout(Fused);
        gridLayout_4->setObjectName("gridLayout_4");
        FusedVideoWidget = new QWidget(Fused);
        FusedVideoWidget->setObjectName("FusedVideoWidget");
        FusedVideoWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0)"));

        gridLayout_4->addWidget(FusedVideoWidget, 0, 0, 1, 1);

        tabWidget->addTab(Fused, QString());
        Optical = new QWidget();
        Optical->setObjectName("Optical");
        gridLayout_2 = new QGridLayout(Optical);
        gridLayout_2->setObjectName("gridLayout_2");
        OpticalVideoWidget = new QWidget(Optical);
        OpticalVideoWidget->setObjectName("OpticalVideoWidget");
        OpticalVideoWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0)"));

        gridLayout_2->addWidget(OpticalVideoWidget, 0, 0, 1, 1);

        tabWidget->addTab(Optical, QString());
        Thermal = new QWidget();
        Thermal->setObjectName("Thermal");
        gridLayout = new QGridLayout(Thermal);
        gridLayout->setObjectName("gridLayout");
        ThermalVideoWidget = new QWidget(Thermal);
        ThermalVideoWidget->setObjectName("ThermalVideoWidget");
        ThermalVideoWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0)"));

        gridLayout->addWidget(ThermalVideoWidget, 0, 0, 1, 1);

        tabWidget->addTab(Thermal, QString());

        horizontalLayout->addWidget(tabWidget);

        savisual = new QVBoxLayout();
        savisual->setSpacing(7);
        savisual->setObjectName("savisual");
        savisual->setContentsMargins(-1, 15, -1, -1);
        RadarHLabel = new QLabel(Stream);
        RadarHLabel->setObjectName("RadarHLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RadarHLabel->sizePolicy().hasHeightForWidth());
        RadarHLabel->setSizePolicy(sizePolicy);
        RadarHLabel->setMinimumSize(QSize(0, 40));
        RadarHLabel->setFont(font1);
        RadarHLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        savisual->addWidget(RadarHLabel);

        RadarStatusArea = new QWidget(Stream);
        RadarStatusArea->setObjectName("RadarStatusArea");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(RadarStatusArea->sizePolicy().hasHeightForWidth());
        RadarStatusArea->setSizePolicy(sizePolicy1);
        gridLayout_7 = new QGridLayout(RadarStatusArea);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(RadarStatusArea);
        groupBox_2->setObjectName("groupBox_2");
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setBold(true);
        groupBox_2->setFont(font2);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName("gridLayout_3");
        RedLabel = new QLabel(groupBox_2);
        RedLabel->setObjectName("RedLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(RedLabel->sizePolicy().hasHeightForWidth());
        RedLabel->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setBold(false);
        RedLabel->setFont(font3);
        RedLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(RedLabel, 0, 0, 1, 1);

        BlueLabel = new QLabel(groupBox_2);
        BlueLabel->setObjectName("BlueLabel");
        sizePolicy2.setHeightForWidth(BlueLabel->sizePolicy().hasHeightForWidth());
        BlueLabel->setSizePolicy(sizePolicy2);
        BlueLabel->setFont(font3);
        BlueLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(BlueLabel, 1, 0, 1, 1);

        BlueColor = new QLabel(groupBox_2);
        BlueColor->setObjectName("BlueColor");
        sizePolicy2.setHeightForWidth(BlueColor->sizePolicy().hasHeightForWidth());
        BlueColor->setSizePolicy(sizePolicy2);
        BlueColor->setStyleSheet(QString::fromUtf8("Background-color:rgb(160, 210, 255)"));

        gridLayout_3->addWidget(BlueColor, 0, 1, 1, 1);

        RedColor = new QLabel(groupBox_2);
        RedColor->setObjectName("RedColor");
        sizePolicy2.setHeightForWidth(RedColor->sizePolicy().hasHeightForWidth());
        RedColor->setSizePolicy(sizePolicy2);
        RedColor->setStyleSheet(QString::fromUtf8("Background-color:rgb(255, 200, 200)"));

        gridLayout_3->addWidget(RedColor, 1, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_2, 1, 0, 1, 1);

        gBClObjType = new QGroupBox(RadarStatusArea);
        gBClObjType->setObjectName("gBClObjType");
        sizePolicy1.setHeightForWidth(gBClObjType->sizePolicy().hasHeightForWidth());
        gBClObjType->setSizePolicy(sizePolicy1);
        gBClObjType->setFont(font2);
        gridLayout_5 = new QGridLayout(gBClObjType);
        gridLayout_5->setObjectName("gridLayout_5");
        OffTrackTBtn = new QToolButton(gBClObjType);
        OffTrackTBtn->setObjectName("OffTrackTBtn");
        OffTrackTBtn->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 0)"));

        gridLayout_5->addWidget(OffTrackTBtn, 0, 0, 1, 1);

        OffTrackLabel = new QLabel(gBClObjType);
        OffTrackLabel->setObjectName("OffTrackLabel");
        OffTrackLabel->setFont(font3);

        gridLayout_5->addWidget(OffTrackLabel, 0, 1, 1, 1);

        OnTrackTBtn = new QToolButton(gBClObjType);
        OnTrackTBtn->setObjectName("OnTrackTBtn");
        OnTrackTBtn->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 0, 0)"));

        gridLayout_5->addWidget(OnTrackTBtn, 1, 0, 1, 1);

        OnTrackLabel = new QLabel(gBClObjType);
        OnTrackLabel->setObjectName("OnTrackLabel");
        OnTrackLabel->setFont(font3);

        gridLayout_5->addWidget(OnTrackLabel, 1, 1, 1, 1);


        gridLayout_7->addWidget(gBClObjType, 1, 1, 1, 1, Qt::AlignmentFlag::AlignTop);

        RadarStatus = new QGroupBox(RadarStatusArea);
        RadarStatus->setObjectName("RadarStatus");
        sizePolicy.setHeightForWidth(RadarStatus->sizePolicy().hasHeightForWidth());
        RadarStatus->setSizePolicy(sizePolicy);
        RadarStatus->setMinimumSize(QSize(200, 0));
        RadarStatus->setFont(font2);
        gridLayout_6 = new QGridLayout(RadarStatus);
        gridLayout_6->setObjectName("gridLayout_6");
        label = new QLabel(RadarStatus);
        label->setObjectName("label");
        label->setFont(font3);

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(RadarStatus);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 255, 0)"));

        gridLayout_6->addWidget(label_2, 0, 1, 1, 1);


        gridLayout_7->addWidget(RadarStatus, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, -1, 2, -1);
        RadarBtn = new QPushButton(RadarStatusArea);
        RadarBtn->setObjectName("RadarBtn");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(RadarBtn->sizePolicy().hasHeightForWidth());
        RadarBtn->setSizePolicy(sizePolicy3);
        RadarBtn->setMinimumSize(QSize(0, 10));
        RadarBtn->setMaximumSize(QSize(200, 16777215));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        RadarBtn->setFont(font4);

        horizontalLayout_4->addWidget(RadarBtn);

        RadarLabel = new QLabel(RadarStatusArea);
        RadarLabel->setObjectName("RadarLabel");
        sizePolicy.setHeightForWidth(RadarLabel->sizePolicy().hasHeightForWidth());
        RadarLabel->setSizePolicy(sizePolicy);
        RadarLabel->setMinimumSize(QSize(0, 0));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        RadarLabel->setFont(font5);
        RadarLabel->setStyleSheet(QString::fromUtf8("Background-color:red"));
        RadarLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(RadarLabel);


        gridLayout_7->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        savisual->addWidget(RadarStatusArea, 0, Qt::AlignmentFlag::AlignTop);

        savisual->setStretch(0, 1);

        horizontalLayout->addLayout(savisual);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 3);

        retranslateUi(Stream);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Stream);
    } // setupUi

    void retranslateUi(QWidget *Stream)
    {
        Stream->setWindowTitle(QCoreApplication::translate("Stream", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Fused), QCoreApplication::translate("Stream", "Fused", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Optical), QCoreApplication::translate("Stream", "Optical", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Thermal), QCoreApplication::translate("Stream", "Thermal", nullptr));
        RadarHLabel->setText(QCoreApplication::translate("Stream", "Radar", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Stream", "Range:", nullptr));
        RedLabel->setText(QCoreApplication::translate("Stream", "Max Coverage", nullptr));
        BlueLabel->setText(QCoreApplication::translate("Stream", "Brake Distance", nullptr));
        BlueColor->setText(QString());
        RedColor->setText(QString());
        gBClObjType->setTitle(QCoreApplication::translate("Stream", "Cluster/Object type:", nullptr));
        OffTrackTBtn->setText(QString());
        OffTrackLabel->setText(QCoreApplication::translate("Stream", "Off-Track", nullptr));
        OnTrackTBtn->setText(QString());
        OnTrackLabel->setText(QCoreApplication::translate("Stream", "On-Track", nullptr));
        RadarStatus->setTitle(QCoreApplication::translate("Stream", "Status", nullptr));
        label->setText(QCoreApplication::translate("Stream", "Health", nullptr));
        label_2->setText(QString());
        RadarBtn->setText(QCoreApplication::translate("Stream", "Power", nullptr));
        RadarLabel->setText(QCoreApplication::translate("Stream", "Off", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Stream: public Ui_Stream {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREAM_H
