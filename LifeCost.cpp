#include <iostream>
using namespace std;

void inputLifeCost(double months[4], string monthName);
double getLifeCostSum(double months[4]);
double getLifeCostAverage(double months[4], string monthName);
void getHighestAndLowestLifeCost(double monthsAverage[12]);
double getLifeCostAverageInOneYear(double years[3]);

int main()
{
    cout << "=============================================" << endl;
    cout << "|                                           |" << endl;
    cout << "|========= Program Biaya Kehidupan =========|" << endl;
    cout << "|                                           |" << endl;
    cout << "=============================================" << endl;

    cout << "|           Nama : Erik Rio Setiawan        |" << endl;
    cout << "|           NIM  : 185329168                |" << endl;
    cout << "=============================================" << endl;

    // Declare the variables
    double januari[4];
    double februari[4];
    double maret[4];
    double april[4];
    double mei[4];
    double juni[4];
    double juli[4];
    double agustus[4];
    double september[4];
    double oktober[4];
    double nopember[4];
    double desember[4];

    // Assign the value of all months
    inputLifeCost(januari, "Januari");
    inputLifeCost(februari, "Februari");
    inputLifeCost(maret, "Maret");
    inputLifeCost(april, "April");
    inputLifeCost(mei, "Mei");
    inputLifeCost(juni, "Juni");
    inputLifeCost(juli, "Juli");
    inputLifeCost(agustus, "Agustus");
    inputLifeCost(september, "September");
    inputLifeCost(oktober, "Oktober");
    inputLifeCost(nopember, "Nopember");
    inputLifeCost(desember, "Desember");

    // Calculate the average of life cost in every month
    double averageOfJanuari = getLifeCostAverage(januari, "Januari");
    double averaegeOfFebruari = getLifeCostAverage(februari, "Februari");
    double averageOfMaret = getLifeCostAverage(maret, "Maret");
    double averageOfApril = getLifeCostAverage(april, "April");
    double averageOfMei = getLifeCostAverage(mei, "Mei");
    double averageOfJuni = getLifeCostAverage(juni, "Juni");
    double averageOfJuli = getLifeCostAverage(juli, "Juli");
    double averageOfAgustus = getLifeCostAverage(agustus, "Agustus");
    double averageOfSeptember = getLifeCostAverage(september, "September");
    double averageOfOktober = getLifeCostAverage(oktober, "Oktober");
    double averageOfNopember = getLifeCostAverage(nopember, "Nopember");
    double averageOfDesember = getLifeCostAverage(desember, "Desember");

    // Calculate the average of life cost in one years
    double sumInOneYears[12] = {
        getLifeCostSum(januari),
        getLifeCostSum(februari),
        getLifeCostSum(maret),
        getLifeCostSum(april),
        getLifeCostSum(mei),
        getLifeCostSum(juni),
        getLifeCostSum(juli),
        getLifeCostSum(agustus),
        getLifeCostSum(september),
        getLifeCostSum(oktober),
        getLifeCostSum(nopember),
        getLifeCostSum(desember)};

    double averageInOneYears = getLifeCostAverageInOneYear(sumInOneYears);

    cout << "\nRata-rata biaya hidup dalam satu tahun adalah " << averageInOneYears << endl;

    // Get the the highest and the lowest life cost in one year
    // and determine is highest life cost surplus or inflate
    getHighestAndLowestLifeCost(sumInOneYears);
}

// The method to input every week life cost from user
void inputLifeCost(double months[4], string monthName)
{
    int i = 0;
    cout << "Biaya hidup di bulan " << monthName << endl;
    do
    {
        cout << "Masukkan biaya hidup: ";
        cin >> months[i];
        i++;
    } while (i < 4);
    cout << endl;
}

// The method to get the sum of life cost in every month
double getLifeCostSum(double months[4])
{
    double sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += months[i];
    }
    return sum;
}

// The method to get the average of life cost in every month
double getLifeCostAverage(double months[4], string monthName)
{
    double average = getLifeCostSum(months) / 4;
    cout << "Rata-rata biaya hidup di bulan " << monthName << " adalah " << average << endl;
    return average;
}

// The method to get the average of life cost in one years
double getLifeCostAverageInOneYear(double years[12])
{
    double sum = 0;
    for (int i = 0; i < 12; i++)
    {
        sum += years[i];
    }
    return sum / 12;
}

// The method to get the the highest and the lowest life cost in one year
void getHighestAndLowestLifeCost(double sumInOneYears[12])
{
    double highest = sumInOneYears[0];
    double lowest = sumInOneYears[0];
    for (int i = 0; i < 12; i++)
    {
        if (highest < sumInOneYears[i])
        {
            highest = sumInOneYears[i];
        }
        if (lowest > sumInOneYears[i])
        {
            lowest = sumInOneYears[i];
        }
    }

    cout << "Biaya hidup tertinggi adalah " << highest << endl;
    cout << "Biaya hidup terendah adalah " << lowest << endl;

    // Determine is highest life cost surplus or inflate
    string condition[2];

    if (highest > 2000000)
    {
        condition[0] = "lebih dari";
        condition[1] = "Inflasi";
    }
    else
    {
        condition[0] = "kurang dari";
        condition[1] = "Surflus";
    }

    cout << "Karena biaya hidup tertinggi Anda " << condition[0] << " Rp. 2.000.000,00, maka Anda mengalami " << condition[1] << endl;
}