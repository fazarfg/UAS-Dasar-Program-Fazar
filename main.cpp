#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct ParkingType{
  string vehicle;
  int price;
};

vector<ParkingType> parkingTypes{
  {"Motor", 3000},
  {"Mobil", 5000},
};

vector<char> alphabets{
  'A', 'B', 'C',
};

struct ParkingLot{
  char alphabet;
  int number;
  bool isAvailable;
};

vector<vector<ParkingLot>> parkingLots;

struct ParkingVehicle{
  ParkingType parkingType;
  ParkingLot parkingLot;
};

ParkingVehicle parkingVehicle;

int main() {
  int parkingTime, vihecle, parkingColumn;
  char parkingRow, repeat;

  if (parkingLots.size() == 0) {
    for (char alphabet : alphabets) {
      vector<ParkingLot> row;

      for (int i = 0; i < alphabets.size(); i++) {
        row.push_back({alphabet, i + 1, true});
      }
      
      parkingLots.push_back(row); 
    }
  }

  menu:
    cout << "================ Masuk Parkir Kendaraan ================\n\n";

    for (int i = 0; i < parkingTypes.size(); i++) {
      cout << i + 1 << ". " << parkingTypes[i].vehicle << " : Rp " << parkingTypes[i].price << "/jam\n";
    }
    
    cout << "\nPilih kendaran (1 - " << parkingTypes.size() << ") : ";
    cin >> vihecle;
    parkingVehicle.parkingType.vehicle = parkingTypes[vihecle - 1].vehicle;
    parkingVehicle.parkingType.price = parkingTypes[vihecle - 1].price;

    system("cls");

    if (vihecle > 0 && vihecle <= parkingTypes.size()) {
      time:
        cout << "Masukkan lama parkir/jam (minimal 1 jam) : ";
        cin >> parkingTime;

        system("cls");

        if (parkingTime > 0) {
          for (auto & row : parkingLots) {
            for (auto & column : row) {
            cout << column.alphabet << column.number << (column.isAvailable ? "" : "*") << " ";
          }

          cout << "\n";
        }

        row:
          cout << "Masukkan baris tempat parkir (" << alphabets.front() << " - " << alphabets.back() << ") : ";
          cin >> parkingRow;

          column:
            cout << "\nMasukkan kolom tempat parkir (1 - " << alphabets.size() << ") : ";
            cin >> parkingColumn;

            system("cls");

            for (auto & row : parkingLots) {
              for (auto & column : row) {
                if (parkingRow == column.alphabet) {
                  if (parkingColumn == column.number) {
                    parkingVehicle.parkingLot.alphabet = parkingRow;
                    parkingVehicle.parkingLot.number = parkingColumn;
                    column.isAvailable = false;
                  }
                }
              }
            }
        } else {
          goto time;
        } 
    } else {
      goto menu;
    }

    cout << "======== Rincian Parkir ========\n\n";
    cout << "Tipe kendaraan : " << parkingVehicle.parkingType.vehicle << "\n";
    cout << "Harga perjam : Rp " << parkingVehicle.parkingType.price << "\n";
    cout << "Tempat parkir : " << parkingVehicle.parkingLot.alphabet << parkingVehicle.parkingLot.number << "\n";
    cout << "Lama parkir : " << parkingTime << " jam\n";
    cout << "Total bayar : Rp " << parkingVehicle.parkingType.price *  parkingTime << "\n";

    cout << "\nKembali ke menu? (y/t) : ";
    cin >> repeat;

    system("cls");

    if (repeat == 'y') {
      goto menu;
    } else {
      abort();
    }
}