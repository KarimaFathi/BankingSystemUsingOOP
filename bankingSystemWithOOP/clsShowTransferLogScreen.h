#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include<vector>
#include<iomanip>
using namespace std;


class clsShowTransferLogScreen : protected clsScreen {

    private:
        static void _printTransferLogRecordLine(vector<string > vTransferLogData) {
            if (vTransferLogData.size() < 7) {
                cout << "Invalid data line: less than 7 fields." << endl;
                return; // Or handle differently
            }
            std::cout << setw(8) << left << "" << "| " << left << setw(20) << vTransferLogData[0];
            std::cout << "| " << left << setw(12) << vTransferLogData[1];
            std::cout << "| " << left << setw(12) << vTransferLogData[2];
            std::cout << "| " << left << setw(12) << vTransferLogData[3];
            std::cout << "| " << left << setw(12) << vTransferLogData[4];
            std::cout << "| " << left << setw(12) << vTransferLogData[5];
            std::cout << "| " << left << setw(12) << vTransferLogData[6] << endl;
        }

    public:
        static void showTransferLogDataList() {
            string title = "Transfer Log List Screen";
            vector<vector<string>> vTransferLogData = clsUser::getTransferLogDataList();
            string subtitle = "(" + to_string(vTransferLogData.size()) + ") Record(s) ";
            _drawScreenHeader(title, subtitle);

            std::cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";
            std::cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
            std::cout << "| " << left << setw(12) << "S.AccN";
            std::cout << "| " << left << setw(12) << "D.AccN";
            std::cout << "| " << left << setw(12) << "Amount";
            std::cout << "| " << left << setw(12) << "S.Balance";
            std::cout << "| " << left << setw(12) << "D.Balance";
            std::cout << "| " << left << setw(12) << "User";
            std::cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";


            for (vector<string>& TransferLogData : vTransferLogData) {
                _printTransferLogRecordLine(TransferLogData);
            }

            std::cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n";


        }


 };


