#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>
#include "CSVparser.hpp"

using namespace std;

struct Bid {
    string bidId;
    string title;
    string fund;
    double amount;
    Bid() : amount(0.0) {}
};

void displayBid(const Bid& bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | " << bid.fund << endl;
}

vector<Bid> loadBids(const string& csvPath) {
    cout << "Loading CSV file " << csvPath << endl;
    vector<Bid> bids;

    try {
        csv::Parser file = csv::Parser(csvPath);
        for (int i = 0; i < file.rowCount(); i++) {
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = stod(file[i][4].substr(1));
            bids.push_back(bid);
        }
    } catch (const csv::Error& e) {
        cerr << e.what() << endl;
    }
    return bids;
}

int partition(vector<Bid>& bids, int begin, int end) {
    int low = begin;
    int high = end;
    int pivot = low + (high - low) / 2;

    while (true) {
        while (bids[low].title < bids[pivot].title) {
            ++low;
        }
        while (bids[pivot].title < bids[high].title) {
            --high;
        }
        if (low >= high) {
            return high;
        }
        swap(bids[low], bids[high]);
        ++low;
        --high;
    }
}

void quickSort(vector<Bid>& bids, int begin, int end) {
    if (begin >= end) {
        return;
    }

    int mid = partition(bids, begin, end);
    quickSort(bids, begin, mid);
    quickSort(bids, mid + 1, end);
}

void selectionSort(vector<Bid>& bids) {
    size_t size = bids.size();
    for (size_t pos = 0; pos < size - 1; ++pos) {
        int min = pos;
        for (size_t i = pos + 1; i < size; ++i) {
            if (bids[i].title < bids[min].title) {
                min = i;
            }
        }
        if (min != pos) {
            swap(bids[pos], bids[min]);
        }
    }
}

int main(int argc, char* argv[]) {
    string csvPath = (argc > 1) ? argv[1] : "eBid_Monthly_Sales_Dec_2016.csv";
    vector<Bid> bids;
    clock_t ticks;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:\n"
             << "  1. Load Bids\n"
             << "  2. Display All Bids\n"
             << "  3. Selection Sort All Bids\n"
             << "  4. Quick Sort All Bids\n"
             << "  9. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ticks = clock();
            bids = loadBids(csvPath);
            cout << bids.size() << " bids read\n"
                 << "time: " << (clock() - ticks) * 1.0 / CLOCKS_PER_SEC << " seconds\n";
            break;
        case 2:
            for (const auto& bid : bids) {
                displayBid(bid);
            }
            cout << endl;
            break;
        case 3:
            ticks = clock();
            selectionSort(bids);
            cout << "Selection Sort: " << (clock() - ticks) * 1.0 / CLOCKS_PER_SEC << " seconds\n";
            break;
        case 4:
            ticks = clock();
            quickSort(bids, 0, bids.size() - 1);
            cout << "Quick Sort: " << (clock() - ticks) * 1.0 / CLOCKS_PER_SEC << " seconds\n";
            break;
        }
    }

    cout << "Goodbye.\n";
    return 0;
}

/*Changes made:

1. **Removed Unused Code:** I removed the `getBid` function, which was not used in the program.
2. **Simplified File Loading:** The `loadBids` function now uses `stod` to convert strings to doubles, which eliminates the need for the `strToDouble` function.
3. **Streamlined
*/