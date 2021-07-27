#include <bits/stdc++.h>
using namespace std;
#define EXPO 1
#define LIN 2

int main(int argc, char** argv)
{
    if (argc < 8)
    {
        cout << "Usage :" << endl;
        cout << "./cw ki km kn kf ps T outputFile" << endl;
        return 0;
    }
    double ki, km, kn, kf, ps;
    int T;
    double MSS = 1.0;
    double RWS = 1024.0;
    double cw = ki * MSS;                                           // cw = ki * MSS, MSS = 1 KB
    cw = ceil(cw);
    int thresh = INT_MAX;                                                  
    ki = stod(argv[1]);
    km = stod(argv[2]);
    kn = stod(argv[3]);
    kf = stod(argv[4]);
    ps = stod(argv[5]);
    T = stoi(argv[6]);
    string outputFile = argv[7];
    int misValue = int(ps * 10000);                                 // val <= misValue , ACK is missed
    int phase = EXPO;
    fstream my_file;
    my_file.open(outputFile,ios::out);
    while (T--)
    {
        int ackVal = rand() % 10000;
        if(ackVal <= misValue)
        {
            thresh = cw/2;
            cw = max(1.0, kf * cw);
            cw = ceil(cw);
            if (cw < thresh) 
            {
                phase = EXPO;
            }
            else
            {
                phase = LIN;
            }
        }
        else 
        {
            if (phase == EXPO)
            {
                cw = min(cw + (km * MSS), RWS);
                cw = ceil(cw);
                if (cw >= thresh) phase = LIN;
            } 
            else if (phase == LIN) 
            {
                cw = min(cw + (kn * MSS * MSS/cw), RWS);
                cw = ceil(cw);
            }
        }
        my_file << cw << endl;
    }
    my_file.close();
    return 0;
}