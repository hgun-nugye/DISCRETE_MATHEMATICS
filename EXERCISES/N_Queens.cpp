#include <bits/stdc++.h>
using namespace std;

int n;
long long soCach = 0;

bool cotDaDung[30]; //cot dat quan hau
bool cheoChinh[60]; //cheo chinh dat quan hau
bool cheoPhu[60]; // cheo phu dat quan hau

void DatHau(int hang) {
    if (hang == n) {
        soCach++; //dat het n quan hau => +1 cach
        return;
    }

    for (int cot = 0; cot < n; cot++) {
        if (!cotDaDung[cot] &&
            !cheoChinh[hang - cot + n] && //hang - cot + n => tranh index am
            !cheoPhu[hang + cot]) 
			{
				//dat hau tam thoi
            cotDaDung[cot] = true;
            cheoChinh[hang - cot + n] = true;
            cheoPhu[hang + cot] = true;

            DatHau(hang + 1); //chuyen sang hang tiep theo

			// bo hau de thu cot khac
            cotDaDung[cot] = false;
            cheoChinh[hang - cot + n] = false;
            cheoPhu[hang + cot] = false;
        }
    }
}

int main() {
    cin >> n;
    DatHau(0);
    cout << soCach;
    return 0;
}
