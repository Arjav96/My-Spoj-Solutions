#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int r, c, k, mr, mc, ar, ac, br, bc, mtop, mleft, mbot, mright, ctop, cleft, cbot, cright;
	scanf("%d%d%d", &r, &c, &k);
	while(k--) {
		scanf("%d%d%d%d%d%d", &mr, &mc, &ar, &ac, &br, &bc);
		if((mr >= ar && mr >= br)||(mr <= ar && mr <= br) ||(mc >= ac && mc >= bc) ||(mc <= ac && mc <= bc)) printf("YES\n");
		else {
			mtop = abs(mr - 1);
			ctop = min(abs(1-ar)+abs(mc-ac), abs(1-br)+abs(mc-bc));
			mleft = abs(c - mc);
			cleft = min(abs(mr-ar)+abs(c-ac), abs(mr-br)+abs(c-bc));
			mbot = abs(r - mr);
			cbot = min(abs(r-ar)+abs(mc-ac), abs(r-br)+abs(mc-bc));
			mright = abs(mc - 1);
			cright = min(abs(mr-ar)+abs(1-ac), abs(mr-br)+abs(1-bc));
			if(mtop < ctop || mbot < cbot || mleft < cleft || mright < cright) printf("YES\n");
			else printf("NO\n");
		}
	}
} 
