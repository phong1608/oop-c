#include <iostream>

#include <iomanip>

using namespace std;

//Cau 1

class NGUOI

{

	private:

		char hoten[30];

	protected:

		char maso[10];		//bc: bien che, hd: hop dong

		float luong;

	public:

		static int ts;

		NGUOI()

		{

			ts++;

		}

		~NGUOI()

		{

			ts--;

		}

		void nhap()

		{

			cout<<endl<<"Nhap ma so (bc: bien che, hd: hop dong): "; 

			cin.ignore(); cin.get(maso,10);

			cout<<endl<<"Nhap ho ten: "; cin.ignore(); cin.get(hoten, 30);

		}

		void in()

		{

			cout<<endl<<setw(10)<<maso<<setw(30)<<hoten<<setw(12)<<setprecision(2)<<fixed<<luong;

		}

		friend operator<(NGUOI p1, NGUOI p2)

		{

			return p1.luong<p2.luong?1:0;

		}

};

int NGUOI::ts = 0;

//Cau 2

class BIENCHE: virtual public NGUOI

{

	private:

		float luongcb = 1490000, hsl, phucap;

	public:

		void nhap_bc()

		{

			cout<<endl<<"Nhap luong co ban: "; cin>>luongcb;

			cout<<endl<<"Nhap he so luong: "; cin>>hsl;

			cout<<endl<<"Nhap phu cap: "; cin>>phucap;

			luong = luongcb*hsl + phucap;

		}

};

class HOPDONG: virtual public NGUOI

{

	private:

		float tiencong, ngaycong, hsvg;

	public:

		void nhap_hd()

		{

			cout<<endl<<"Nhap tien cong/ngay: "; cin>>tiencong;

			cout<<endl<<"Nhap so ngay cong: "; cin>>ngaycong;

			cout<<endl<<"He so vuot gio: "; cin>>hsvg;

			luong = ngaycong<=26?tiencong*ngaycong:tiencong*(26+hsvg*(ngaycong-26));

		}

};

class VIENCHUC: public BIENCHE, public HOPDONG

{

	public:

		void nhap_vc()

		{

			nhap();			//Goi ham nhap cua lop NGUOI

			if(maso[0]=='b')

				nhap_bc();

			else

				nhap_hd();

		}

		float getluong()

		{

			return luong;

		}

		char getmaso()

		{

			return maso[0];

		}

		void hoanvi(VIENCHUC &p1, VIENCHUC &p2)

		{

			VIENCHUC tg = p1;

			p1 = p2;

			p2 = tg;

		}

		VIENCHUC *next;

};

int main()

{

	//Tao danh sach lien ket don

	VIENCHUC *d = NULL, *c = NULL, *node = NULL;

	char ch = 't';

	while(ch=='t')

	{

		node = new VIENCHUC;

		node->nhap_vc();

		node->next = NULL;

		if(d==NULL)

		{

			d = node;

			c = node;

		}

		else

		{

			c->next = node;

			c = node;

		}

		cout<<endl<<"Tiep tuc (t: tiep): "; cin>>ch;

	}

	//Sap xep danh sach lien ket don

	VIENCHUC *i=d, *j;

	while(i!=NULL){

		j = i->next;

		while(j!=NULL){

			if(i->getluong()<j->getluong())

			{

				//Hoan vi noi dung cua 2 con tro i va j	

			}

			j = j->next;

		}

		i = i->next;

	}

	VIENCHUC *s = d;

	while(s!=NULL){

		s->in();

		s = s->next;

	}

/*	

	int n;	//Nhap so phan tu cua danh sach 

	cout<<endl<<"Nhap so nhan vien: "; cin>>n;

	VIENCHUC *ds = new VIENCHUC[n];	//Khai bao va cap phat bo nho cho ds

	//Lap danh sach lien ket don.

	//Nhap thong tin chi tiet cho tung nhan vien

	for(int i=0; i<n; i++)

		ds[i].nhap_vc();

	cout<<endl<<"Danh sach nhan vien.";

	for(int i=0; i<n; i++)

		ds[i].in();

	//Sap xep danh sach theo thu tu giam dan cua luong

	for(int i=0; i<n; i++)

		for(int j=i+1; j<n; j++)

			//if(ds[i].getluong()<ds[j].getluong())

			if(ds[i]<ds[j])

				hoanvi(ds[i], ds[j]);

	//In ds sau khi sap xep

	

	//In ra tong so nhan vien

	cout<<endl<<NGUOI::ts;

*/

}