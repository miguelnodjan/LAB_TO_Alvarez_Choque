#include "countryinfo.h"

#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QFrame>
#include <QFont>
#include <QListWidgetItem>

CountryInfoWindow::CountryInfoWindow(QWidget *parent)
    : QMainWindow(parent)
    , countryList(nullptr)
    , titleLabel(nullptr)
    , capitalLabel(nullptr)
    , languageLabel(nullptr)
    , currencyLabel(nullptr)
    , populationLabel(nullptr)
{
    setupUI();
    loadCountryData();
}

CountryInfoWindow::~CountryInfoWindow(){}

void CountryInfoWindow::setupUI()
{
    setWindowTitle("Información de Países");
    setGeometry(100, 100, 600, 400);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    //lado izquierdo
    countryList = new QListWidget(this);
    countryList->setFixedWidth(200);
    connect(countryList, &QListWidget::itemClicked,
            this, &CountryInfoWindow::onCountrySelected);
    mainLayout->addWidget(countryList);

    //lado derecho
    QFrame *infoFrame = new QFrame(this);
    infoFrame->setFrameStyle(QFrame::Box);
    QVBoxLayout *infoLayout = new QVBoxLayout(infoFrame);

    titleLabel = new QLabel("Seleccione un país", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    infoLayout->addWidget(titleLabel);

    capitalLabel = new QLabel("Capital: -", this);
    languageLabel = new QLabel("Idioma: -", this);
    currencyLabel = new QLabel("Moneda: -", this);
    populationLabel = new QLabel("Población: -", this);

    QFont infoFont;
    infoFont.setPointSize(12);

    QLabel* labels[] = {capitalLabel, languageLabel, currencyLabel, populationLabel};
    for (QLabel* label : labels) {
        label->setFont(infoFont);
        label->setStyleSheet("padding: 10px;");
        infoLayout->addWidget(label);
    }

    infoLayout->addStretch();
    mainLayout->addWidget(infoFrame);
}

void CountryInfoWindow::loadCountryData()
{
    countriesData.insert("Argentina ", CountryData("Buenos Aires", "Español", "Peso Argentino", "45 millones"));
    countriesData.insert("Brasil", CountryData("Brasilia", "Portugués", "Real Brasileño", "214 millones"));
    countriesData.insert("Chile", CountryData("Santiago", "Español", "Peso Chileno", "19 millones"));
    countriesData.insert("Colombia", CountryData("Bogotá", "Español", "Peso Colombiano", "51 millones"));
    countriesData.insert("España", CountryData("Madrid", "Español", "Euro", "47 millones"));
    countriesData.insert("Francia", CountryData("París", "Francés", "Euro", "68 millones"));
    countriesData.insert("Italia", CountryData("Roma", "Italiano", "Euro", "59 millones"));
    countriesData.insert("México", CountryData("Ciudad de México", "Español", "Peso Mexicano", "126 millones"));
    countriesData.insert("Estados Unidos", CountryData("Washington D.C.", "Inglés", "Dólar Estadounidense", "331 millones"));
    countriesData.insert("Japón", CountryData("Tokio", "Japonés", "Yen Japonés", "126 millones"));

    QStringList countryNames = countriesData.keys();
    countryNames.sort();

    for (const QString &country : countryNames) {
        countryList->addItem(country);
    }
}

void CountryInfoWindow::onCountrySelected(QListWidgetItem *item)
{
    QString countryName = item->text();

    if (countriesData.contains(countryName)) {
        CountryData data = countriesData[countryName];

        titleLabel->setText(countryName);
        capitalLabel->setText("Capital: " + data.capital);
        languageLabel->setText("Idioma: " + data.language);
        currencyLabel->setText("Moneda: " + data.currency);
        populationLabel->setText("Población: " + data.population);
    }
}
