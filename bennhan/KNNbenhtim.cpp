#include<bits/stdc++.h>
using namespace std;
struct T{
	float x1,x2;
	float z;
	bool nhan;
};
int n=20;
		T a[100];
		T b;
void sapxep(){
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	if(a[i].z>a[j].z)	swap(a[i],a[j]);
}
void nhap(){
	ifstream ip("bennhan.txt");//dia chi file training dataset	
		for(int i=1;i<=n;i++){
			ip>>a[i].x1>>a[i].x2>>a[i].nhan;
		}
	ip.close();
}
void xuat(){
	for(int i=1;i<=n;i++){
			cout<<a[i].x1<<" "<<a[i].x2<<" "<<a[i].nhan<<endl;
	}
}

main(){
	   b.x1=7;b.x2=5;	//data test
	/*	a[1].x1=4;a[1].x2=3;a[1].nhan='+';
		a[2].x1=3;a[2].x2=7;a[2].nhan='+';
		a[3].x1=7;a[3].x2=4;a[3].nhan='+';
		a[4].x1=4;a[4].x2=1;a[4].nhan='+';
		a[5].x1=6;a[5].x2=5;a[5].nhan='+';
		a[6].x1=5;a[6].x2=6;a[6].nhan='+';
		a[7].x1=3;a[7].x2=7;a[7].nhan='+';
		a[8].x1=6;a[8].x2=2;a[8].nhan='+';
		a[9].x1=4;a[9].x2=6;a[9].nhan='-';
		a[10].x1=4;a[10].x2=4;a[10].nhan='-';
		a[11].x1=5;a[11].x2=8;a[11].nhan='-';
		a[12].x1=7;a[12].x2=8;a[12].nhan='-';
		a[13].x1=7;a[13].x2=6;a[13].nhan='-';
		a[14].x1=4;a[14].x2=10;a[14].nhan='-';
		a[15].x1=9;a[15].x2=7; a[15].nhan='-';
		a[16].x1=5;a[16].x2=4; a[16].nhan='-';
		a[17].x1=8;a[17].x2=5; a[17].nhan='-';
		a[18].x1=6;a[18].x2=6; a[18].nhan='-';
		a[19].x1=7;a[19].x2=4; a[19].nhan='-';
		a[20].x1=8;a[20].x2=8; a[20].nhan='-';	
		xuat();*/
		nhap();
		
		for(int i=1;i<=n;i++){
			a[i].z=sqrt((a[i].x1-b.x1)*(a[i].x1-b.x1)+(a[i].x2-b.x2)*(a[i].x2-b.x2));
		}
		sapxep();
		cout<<"sau khi sap xep: "<<endl;
		for(int i=1;i<=n;i++){
			cout<<setw(3)<<i<<" "<<setw(8)<<a[i].z<<" "<<a[i].nhan<<endl;
		}
		int k=0, count;
		while(k!=-1){
		count=0;
		cout<<"nhap k: ";
		cin>>k;
		b.nhan=0;
		for(int i=1;i<=k;i++)
			if(a[i].nhan==1) count++;
		if(k-count<count) b.nhan=1;
		cout<<"nhan cua training dataset se la: "<<b.nhan<<endl;
	}
}
