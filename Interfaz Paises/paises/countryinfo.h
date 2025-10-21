#ifndef COUNTRYINFO_H
#define COUNTRYINFO_H

#include <QMainWindow>
#include <QMap>
#include <QString>

class QListWidget;
class QListWidgetItem;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QWidget;
class QFrame;

struct CountryData {
    QString capital;
    QString language;
    QString currency;
    QString population;

    CountryData() = default;

    CountryData(const QString &cap, const QString &lang,
                const QString &curr = "", const QString &pop = "")
        : capital(cap), language(lang), currency(curr), population(pop) {}
};

class CountryInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CountryInfoWindow(QWidget *parent = nullptr);
    ~CountryInfoWindow();

private slots:
    void onCountrySelected(QListWidgetItem *item);

private:
    void setupUI();
    void loadCountryData();

    QListWidget *countryList;
    QLabel *titleLabel;
    QLabel *capitalLabel;
    QLabel *languageLabel;
    QLabel *currencyLabel;
    QLabel *populationLabel;

    QMap<QString, CountryData> countriesData;
};

#endif // COUNTRYINFO_H
