/********************************************************************************
** Form generated from reading UI file 'arx_settings.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARX_SETTINGS_H
#define UI_ARX_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ARX_Settings
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Button_save;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_cancel;
    QFrame *frame_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_4;
    QSpinBox *spin_transport_delay;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_11;
    QDoubleSpinBox *double_spin_standard_dev;
    QFrame *frame_4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_5;
    QCheckBox *checkBox_limit_ster;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_limit_max_ster;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_limit_min_ster;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_8;
    QCheckBox *checkBox_limit_reg;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_limit_max_reg;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_limit_min_reg;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea_wsp_B;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *button_wsp_B_add;
    QPushButton *button_wsp_B_del;
    QSpacerItem *verticalSpacer_2;
    QPushButton *button_wsp_B_clear;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea_wsp_A;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *button_wsp_A_add;
    QPushButton *button_wsp_A_del;
    QSpacerItem *verticalSpacer;
    QPushButton *button_wsp_A_clear;

    void setupUi(QDialog *ARX_Settings)
    {
        if (ARX_Settings->objectName().isEmpty())
            ARX_Settings->setObjectName("ARX_Settings");
        ARX_Settings->resize(610, 590);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ARX_Settings->sizePolicy().hasHeightForWidth());
        ARX_Settings->setSizePolicy(sizePolicy);
        ARX_Settings->setMinimumSize(QSize(610, 590));
        ARX_Settings->setMaximumSize(QSize(610, 590));
        layoutWidget = new QWidget(ARX_Settings);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(200, 550, 214, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Button_save = new QPushButton(layoutWidget);
        Button_save->setObjectName("Button_save");

        horizontalLayout->addWidget(Button_save);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Button_cancel = new QPushButton(layoutWidget);
        Button_cancel->setObjectName("Button_cancel");

        horizontalLayout->addWidget(Button_cancel);

        frame_3 = new QFrame(ARX_Settings);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(460, 370, 131, 171));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        layoutWidget1 = new QWidget(frame_3);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 111, 154));
        verticalLayout_16 = new QVBoxLayout(layoutWidget1);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4->setWordWrap(true);

        verticalLayout_14->addWidget(label_4);

        spin_transport_delay = new QSpinBox(layoutWidget1);
        spin_transport_delay->setObjectName("spin_transport_delay");
        spin_transport_delay->setMinimum(1);
        spin_transport_delay->setMaximum(999);
        spin_transport_delay->setValue(1);

        verticalLayout_14->addWidget(spin_transport_delay);


        verticalLayout_16->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName("label_11");
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_11->setWordWrap(true);

        verticalLayout_15->addWidget(label_11);

        double_spin_standard_dev = new QDoubleSpinBox(layoutWidget1);
        double_spin_standard_dev->setObjectName("double_spin_standard_dev");

        verticalLayout_15->addWidget(double_spin_standard_dev);


        verticalLayout_16->addLayout(verticalLayout_15);

        frame_4 = new QFrame(ARX_Settings);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(20, 370, 431, 171));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        layoutWidget2 = new QWidget(frame_4);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(20, 10, 392, 137));
        verticalLayout_13 = new QVBoxLayout(layoutWidget2);
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_13->addWidget(label_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName("label_5");

        verticalLayout_11->addWidget(label_5);

        checkBox_limit_ster = new QCheckBox(layoutWidget2);
        checkBox_limit_ster->setObjectName("checkBox_limit_ster");

        verticalLayout_11->addWidget(checkBox_limit_ster);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName("label_6");

        horizontalLayout_4->addWidget(label_6);

        doubleSpinBox_limit_max_ster = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_limit_max_ster->setObjectName("doubleSpinBox_limit_max_ster");
        doubleSpinBox_limit_max_ster->setMinimumSize(QSize(132, 0));
        doubleSpinBox_limit_max_ster->setMinimum(-9999.000000000000000);
        doubleSpinBox_limit_max_ster->setMaximum(9999.000000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_limit_max_ster);


        verticalLayout_11->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName("label_7");

        horizontalLayout_5->addWidget(label_7);

        doubleSpinBox_limit_min_ster = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_limit_min_ster->setObjectName("doubleSpinBox_limit_min_ster");
        doubleSpinBox_limit_min_ster->setMinimumSize(QSize(132, 0));
        doubleSpinBox_limit_min_ster->setMinimum(-9999.000000000000000);
        doubleSpinBox_limit_min_ster->setMaximum(9999.000000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox_limit_min_ster);


        verticalLayout_11->addLayout(horizontalLayout_5);


        horizontalLayout_8->addLayout(verticalLayout_11);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName("label_8");

        verticalLayout_12->addWidget(label_8);

        checkBox_limit_reg = new QCheckBox(layoutWidget2);
        checkBox_limit_reg->setObjectName("checkBox_limit_reg");

        verticalLayout_12->addWidget(checkBox_limit_reg);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName("label_9");

        horizontalLayout_6->addWidget(label_9);

        doubleSpinBox_limit_max_reg = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_limit_max_reg->setObjectName("doubleSpinBox_limit_max_reg");
        doubleSpinBox_limit_max_reg->setMinimumSize(QSize(132, 0));
        doubleSpinBox_limit_max_reg->setMinimum(-9999.000000000000000);
        doubleSpinBox_limit_max_reg->setMaximum(9999.000000000000000);

        horizontalLayout_6->addWidget(doubleSpinBox_limit_max_reg);


        verticalLayout_12->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName("label_10");

        horizontalLayout_7->addWidget(label_10);

        doubleSpinBox_limit_min_reg = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_limit_min_reg->setObjectName("doubleSpinBox_limit_min_reg");
        doubleSpinBox_limit_min_reg->setMinimumSize(QSize(132, 0));
        doubleSpinBox_limit_min_reg->setMinimum(-9999.000000000000000);
        doubleSpinBox_limit_min_reg->setMaximum(9999.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_limit_min_reg);


        verticalLayout_12->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout_12);


        verticalLayout_13->addLayout(horizontalLayout_8);

        layoutWidget3 = new QWidget(ARX_Settings);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(310, 20, 281, 341));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(layoutWidget3);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_2);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_9->addWidget(label_2);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        scrollArea_wsp_B = new QScrollArea(frame_2);
        scrollArea_wsp_B->setObjectName("scrollArea_wsp_B");
        scrollArea_wsp_B->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 98, 28));
        scrollArea_wsp_B->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_3->addWidget(scrollArea_wsp_B);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        button_wsp_B_add = new QPushButton(frame_2);
        button_wsp_B_add->setObjectName("button_wsp_B_add");
        QFont font;
        font.setPointSize(14);
        button_wsp_B_add->setFont(font);

        verticalLayout_4->addWidget(button_wsp_B_add);

        button_wsp_B_del = new QPushButton(frame_2);
        button_wsp_B_del->setObjectName("button_wsp_B_del");
        button_wsp_B_del->setFont(font);

        verticalLayout_4->addWidget(button_wsp_B_del);

        verticalSpacer_2 = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        button_wsp_B_clear = new QPushButton(frame_2);
        button_wsp_B_clear->setObjectName("button_wsp_B_clear");

        verticalLayout_4->addWidget(button_wsp_B_clear);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_10->addLayout(horizontalLayout_3);


        verticalLayout_9->addLayout(verticalLayout_10);


        verticalLayout_8->addLayout(verticalLayout_9);


        verticalLayout_3->addWidget(frame_2);

        layoutWidget4 = new QWidget(ARX_Settings);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(20, 20, 281, 341));
        verticalLayout_2 = new QVBoxLayout(layoutWidget4);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(layoutWidget4);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_7 = new QVBoxLayout(frame);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 20));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        scrollArea_wsp_A = new QScrollArea(frame);
        scrollArea_wsp_A->setObjectName("scrollArea_wsp_A");
        scrollArea_wsp_A->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 98, 28));
        scrollArea_wsp_A->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea_wsp_A);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        button_wsp_A_add = new QPushButton(frame);
        button_wsp_A_add->setObjectName("button_wsp_A_add");
        button_wsp_A_add->setFont(font);

        verticalLayout->addWidget(button_wsp_A_add);

        button_wsp_A_del = new QPushButton(frame);
        button_wsp_A_del->setObjectName("button_wsp_A_del");
        button_wsp_A_del->setFont(font);

        verticalLayout->addWidget(button_wsp_A_del);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        button_wsp_A_clear = new QPushButton(frame);
        button_wsp_A_clear->setObjectName("button_wsp_A_clear");

        verticalLayout->addWidget(button_wsp_A_clear);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_2->addWidget(frame);


        retranslateUi(ARX_Settings);

        QMetaObject::connectSlotsByName(ARX_Settings);
    } // setupUi

    void retranslateUi(QDialog *ARX_Settings)
    {
        ARX_Settings->setWindowTitle(QCoreApplication::translate("ARX_Settings", "Dialog", nullptr));
        Button_save->setText(QCoreApplication::translate("ARX_Settings", "Zapisz", nullptr));
        Button_cancel->setText(QCoreApplication::translate("ARX_Settings", "Anuluj", nullptr));
        label_4->setText(QCoreApplication::translate("ARX_Settings", "Op\303\263\305\272nienie transportowe", nullptr));
        label_11->setText(QCoreApplication::translate("ARX_Settings", "Odchylenie standardowe zak\305\202ucenia", nullptr));
        label_3->setText(QCoreApplication::translate("ARX_Settings", "Limity warto\305\233ci modelu ARX", nullptr));
        label_5->setText(QCoreApplication::translate("ARX_Settings", "Warto\305\233\304\207 steruj\304\205ca", nullptr));
        checkBox_limit_ster->setText(QCoreApplication::translate("ARX_Settings", "stosuj limity", nullptr));
        label_6->setText(QCoreApplication::translate("ARX_Settings", "MAX", nullptr));
        label_7->setText(QCoreApplication::translate("ARX_Settings", "MIN", nullptr));
        label_8->setText(QCoreApplication::translate("ARX_Settings", "Warto\305\233\304\207 regulowana", nullptr));
        checkBox_limit_reg->setText(QCoreApplication::translate("ARX_Settings", "stosuj limity", nullptr));
        label_9->setText(QCoreApplication::translate("ARX_Settings", "MAX", nullptr));
        label_10->setText(QCoreApplication::translate("ARX_Settings", "MIN", nullptr));
        label_2->setText(QCoreApplication::translate("ARX_Settings", "Wsp\303\263\305\202czyniki B", nullptr));
        button_wsp_B_add->setText(QCoreApplication::translate("ARX_Settings", "+", nullptr));
        button_wsp_B_del->setText(QCoreApplication::translate("ARX_Settings", "-", nullptr));
        button_wsp_B_clear->setText(QCoreApplication::translate("ARX_Settings", "Wyczy\305\233\304\207", nullptr));
        label->setText(QCoreApplication::translate("ARX_Settings", "Wsp\303\263\305\202czyniki A", nullptr));
        button_wsp_A_add->setText(QCoreApplication::translate("ARX_Settings", "+", nullptr));
        button_wsp_A_del->setText(QCoreApplication::translate("ARX_Settings", "-", nullptr));
        button_wsp_A_clear->setText(QCoreApplication::translate("ARX_Settings", "Wyczy\305\233\304\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ARX_Settings: public Ui_ARX_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARX_SETTINGS_H
