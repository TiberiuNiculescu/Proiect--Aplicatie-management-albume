#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Persoana
{

     string nume;
     int varsta;
    public:
        Persoana(){}
        Persoana(string vnume,int vvarsta):nume(vnume),varsta(vvarsta){}
        virtual ~Persoana(){}

        string getNume(){return nume;}
        int getVarsta(){return varsta;}

        void setNume(string vnume){nume=vnume;}
        void setVarsta(int vvarsta){varsta=vvarsta;}

        virtual void afisare(){cout<<"NUME:"<<getNume()<<" VARSTA:"<<getVarsta()<<endl;}

};


class Track
{
        int pozitie;
        string nume;
        int durata;
    public:
        Track(){}
        Track(int vpozitie, string vnume, int vdurata):pozitie(vpozitie),nume(vnume),durata(vdurata){}
        virtual ~Track(){}

        string getNume(){return nume;}
        int getPozitie(){return pozitie;}
        int getDurata(){return durata;}

        void setNume(string vnume){nume=vnume;}
        void setPozitie(int vpozitie){pozitie=vpozitie;}
        void setDurata(int vdurata){durata=vdurata;}

        void afisare(){
            cout<<"DENUMIRE Track:"<<getNume()<<" POZITIE:"<<getPozitie()<<" DURATA:"<<getDurata()<<" Sec"<<endl;
        }

        void modific(string vnume,int vpozitie, int vdurata){
        setNume(vnume);
        setPozitie(vpozitie);
        setDurata(vdurata);
        }
};

class Album
{
        string nume;
        int anAparitie;
        vector <Track*> T;
    public:
        Album(){}
        void adaugTrack(string vnume, int vdurata)
        {
            int vpozitie=T.capacity();
            vpozitie++;
            T.push_back(new Track(vpozitie,vnume,vdurata));

        }
        void stergTrack(int vpozitie)
        {
        int gasit=0;
        vector<Track*>::iterator its;
        for (its=T.begin();its!=T.end();its++)
                 if((*its)->getPozitie()==vpozitie){gasit=1;
                                                   T.erase(its);
                                                   }
        if(gasit==1)cout<<" Am sters Track-ul "<<vpozitie;
        else cout<<"Nu exista Track-ul "<<vpozitie;
        }

        Album(string vnume,int vanAparitie):nume(vnume),anAparitie(vanAparitie)
        {
            T.clear();
            int nr,vdurata;
            string vnumele;
            char s[100];
            cout<<"Dati numar de track-uri=";cin>>nr;cin.get();
            if(nr==0)cout<<"Albumul "<<getNume()<<" nu are track-uri"<<endl;
            else {for(int i=1;i<=nr;i++)
                      {vnumele="";
                       cout<<"dati nume=";cin.getline(s,100,'\n');
                       vnumele.append(s);
                       cout<<"dati durata=";cin>>vdurata;cin.get();
                        T.push_back(new Track(i,vnumele,vdurata));

                      }
                 }}
        virtual ~Album(){}

        string getNume(){return nume;}
        int getanAparitie(){return anAparitie;}
        int getNrTrack(){return T.size();}

        void setNume(string vnume){nume=vnume;}
        void setanAparitie(int vanAparitie){anAparitie=vanAparitie;}

        void modific(string vnume, int vanAparitie)
        {
            nume=vnume;
            anAparitie=vanAparitie;
        }
        void afisare(){
        cout<<endl<<"DENUMIRE ALBUM:"<<getNume()<<" AN APARITIE:"<<getanAparitie()<<" NUMAR TRACK-URI:"<<T.size()<<endl;
        cout<<"______________________"<<endl;
        vector<Track*>::iterator its;
        for (its=T.begin();its!=T.end();its++)
                 (*its)->afisare();

        }






};

class Artist : public Persoana
{

        vector<Album*> A;
    public:

        vector <Album *>getAlbume(){return A;}

        Artist(){}
        Artist(string vnume,int vvarsta):Persoana(vnume,vvarsta){
        A.clear();
        int nrAlbume,i,vanAparitie;
        string vnumele;
        char s[100];
        cout<<"dati numar de albume=";cin>>nrAlbume;cin.get();
        if(nrAlbume==0)cout<<getNume()<<"Nu are nici un album"<<endl;
        else{for(i=1;i<=nrAlbume;i++)
                {vnumele="";
                cout<<"Dati nume album=";cin.getline(s,100,'\n');
                vnumele.append(s);
                cout<<"Dati anul aparitie=";cin>>vanAparitie;cin.get();
                A.push_back(new Album(vnumele,vanAparitie));
               }}
        }
        virtual ~Artist(){}


        void afisareAlbume()
        {
          if(A.empty())cout<<" nu exista albume "<<endl;
          else{
          vector<Album*>::iterator itsa;
          for (itsa=A.begin();itsa!=A.end();itsa++)
                (*itsa)->afisare();
          }
        }



        Album * cautAlbum(string vnume)
        {
          if(A.empty()){cout<<" nu exista albume "<<endl;return NULL;}
          else{
          vector<Album*>::iterator itsa;
          for (itsa=A.begin();itsa!=A.end();itsa++)
                if((*itsa)->getNume()==vnume) return (*itsa);

         cout<<"nu exista albumul cu "<<vnume<<endl;
         return NULL;
        }
        }


        void modific(string vnume,int vvarsta)
        {
            setNume(vnume);
            setVarsta(vvarsta);
        }

        void adaugAlbum()
        {
            int nrAlbume=getAlbume().capacity();
            cout<<"Acum Artistul are  "<<nrAlbume<<endl;
            string vnumele;
            char s[100];
            int vanAparitie;
            vnumele="";
            cout<<"Dati nume album=";cin.getline(s,100,'\n');
            vnumele.append(s);
            cout<<"Dati anul aparitie=";cin>>vanAparitie;cin.get();
            A.push_back(new Album(vnumele,vanAparitie));
        }


        void stergAlbum(string vnume)
        {
          if(A.empty()){cout<<" nu exista albume "<<endl;}
          else{vector<Album*>::iterator itsa;
               for (itsa=A.begin();itsa!=A.end();itsa++)
                   if((*itsa)->getNume()==vnume) {cout<<"Acum sterg "<<vnume<<endl;
                                                     A.erase(itsa);
                                                   break;
                                                  }
        }
        }


};

void op_1(){cout<<"Operatii asupra Artistilor"<<endl;}
void op_2(){cout<<"Operatii asupra Albumelor"<<endl;}
void op_3(){cout<<"Operatii asupra Track-urilor"<<endl;}

int main()
{
    char c;
    int op,vvarsta;
    vector <Artist*> Ar;
    string vnume;

    do{
       system("cls");
       cout<<"0-IESIRE din  program"<<endl;
       cout<<"1-Artist"<<endl;
            cout<<"11   -Adauga Artist"<<endl;
            cout<<"12   -Modifica Artist"<<endl;
            cout<<"13   -Sterge Artist"<<endl;
            cout<<"14   -Afisaza toti Artistii"<<endl;
       cout<<"2-Album"<<endl;
            cout<<"21   -Adauga Album"<<endl;
            cout<<"22   -Modifica Album"<<endl;
            cout<<"23   -Sterge Album"<<endl;
            cout<<"24   -Afisaza toate Albumele unui Artist"<<endl;
       cout<<"3-Track"<<endl;
            cout<<"31   -Adauga Track"<<endl;
            cout<<"32   -Modifica Track"<<endl;
            cout<<"33   -Sterge Track"<<endl;

       cout<<"Dati cod operatie:";
       cin>>op;cin.get();
       switch(op)
       {
           case 1:{op_1();c=getch();break;}
           case 2:{op_2();c=getch();break;}
           case 3:{op_3();c=getch();break;}

           case 11:{char s[100];
                    vnume="";
                    cout<<"NUME=";cin.getline(s,100,'\n');
                    vnume.append(s);
                    cout<<"VARSTA=";cin>>vvarsta;
                    Ar.push_back(new Artist(vnume,vvarsta));
                    c=getch();break;}

          case 12:{char s[100];
                   int gasit=0;
                    string numeVechi="";
                    string numeNou="";
                    int varstaNoua;
                    cout<<"NUME de modificat=";cin.getline(s,100,'\n');
                    numeVechi.append(s);
                    cout<<"NUME nou=";cin.getline(s,100,'\n');
                    numeNou.append(s);
                    cout<<"VARSTA noua=";cin>>varstaNoua;
                    vector<Artist*>::iterator its;
                    for (its=Ar.begin();its!=Ar.end();its++)
                              if((*its)->getNume()==numeVechi){gasit=1;
                                                         (*its)->modific(numeNou,varstaNoua);
                                                         }
                   if(gasit==1) cout<<"modificare efectuata "  <<endl;
                   else cout<<numeVechi <<" nu exista!"<<endl;

                    c=getch();break;}
          case 13:{
                   char s[100];
                   int gasit=0;
                    string numeDeSters="";
                    if(Ar.empty())cout<<"NU avem ce sa stergem!";
                    else{cout<<"NUME de sters=";cin.getline(s,100,'\n');
                         numeDeSters.append(s);
                        vector<Artist*>::iterator its;
                        for (its=Ar.begin();its!=Ar.end()&&gasit==0;its++)
                              if((*its)->getNume()==numeDeSters){gasit=1;
                                                                 Ar.erase(its);
                                                                 }
                        if(gasit==1) cout<<"stergere efectuata "  <<endl;
                        else cout<<numeDeSters <<"nu exista!"<<endl;
                         }    }
          case 14:{vector<Artist*>::iterator its;
                  for (its=Ar.begin();its!=Ar.end();its++)
                              {(*its)->afisare();
                               cout<<"__________"<<endl;
                               (*its)->afisareAlbume();
                              }
                  c=getch();break;
                  }


          ///Albume

          case 21:
              {char s[100];
               string vartist="";
               int gasit=0;
               cout<<"NUMELE Artistului caruia ii adaugam un album=";cin.getline(s,100,'\n');
               vartist.append(s);
               vector<Artist*>::iterator its;
               for (its=Ar.begin();its!=Ar.end()&&gasit==0;its++)
                  if((*its)->getNume()==vartist)
                              {gasit=1;
                               /*string numeAlbum="";
                               int vanAparitie;
                               cout<<"Dati nume album de adaugat=";cin.getline(s,100,'\n');
                               numeAlbum.append(s);
                               cout<<"Dati anul aparitie=";cin>>vanAparitie;cin.get();
                               */
                               ///(*its)->getAlbume().push_back(new Album(numeAlbum,vanAparitie));
                               (*its)->adaugAlbum();
                              }
            if(gasit==1) cout<<"Adaugare efectuata pentru "<<vartist  <<endl;
            else cout<<vartist<<"nu exista!"<<endl;
            c=getch();break;}

          case 22:
              {char s[100];
               string vartist="";
               int gasit_artist=0;
               int gasit_album=0;
               cout<<"NUMELE Artistului caruia ii modificam un album=";cin.getline(s,100,'\n');
               vartist.append(s);
               vector<Artist*>::iterator its;
               for (its=Ar.begin();its!=Ar.end();its++)
                    if((*its)->getNume()==vartist)
                               {gasit_artist=1;
                                string numeAlbumVechi="";
                                string numeAlbumNou="";
                                int gasit_album=0;
                                int vanAparitie;
                                cout<<"Dati nume album de modificat=";cin.getline(s,100,'\n');
                                numeAlbumVechi.append(s);
                                cout<<"Dati nume album de nou=";cin.getline(s,100,'\n');
                                numeAlbumNou.append(s);
                                cout<<"Dati anul aparitie=";cin>>vanAparitie;cin.get();

                                Album * adrAlbum=(*its)->cautAlbum(numeAlbumVechi);
                                if(adrAlbum==NULL)gasit_album=0;
                                else gasit_album=1;

                                if(gasit_album==0)cout<<"Nu am gasit albumul "<<numeAlbumVechi<<" pentru "<<vartist<<endl;
                                else {adrAlbum->modific(numeAlbumNou,vanAparitie);
                                        cout<<"modificare efectuata pentru "<<numeAlbumVechi<<" cu "<<numeAlbumNou<<endl;
                                       }
                            }
                   if(gasit_artist==1) cout<<"Modificare  efectuata pentru "<<vartist  <<endl;
                   else cout<<vartist<<"nu exista!"<<endl;

                    c=getch();break;}

          case 23:{
                  ///sterg albumul unui artist
                  char s[100];
               string vartist="";
               int gasit_artist=0;
               int gasit_album=0;
               cout<<"NUMELE Artistului caruia ii stergem un album=";cin.getline(s,100,'\n');
               vartist.append(s);
               vector<Artist*>::iterator its;
               for (its=Ar.begin();its!=Ar.end();its++)
                    if((*its)->getNume()==vartist)
                               {gasit_artist=1;
                                string numeAlbumSters="";
                                int gasit_album=0;
                                cout<<"Dati nume album de sters=";cin.getline(s,100,'\n');
                                numeAlbumSters.append(s);
                                  ///
                                Album * adrAlbum=(*its)->cautAlbum(numeAlbumSters);

                                if(adrAlbum==NULL)gasit_album=0;
                                else gasit_album=1;

                                if(gasit_album==0)cout<<"Nu am gasit albumul "<<numeAlbumSters<<" pentru "<<vartist<<endl;
                                else {

                                        (*its)->stergAlbum(numeAlbumSters);

                                        cout<<"Am sters albumul "<<numeAlbumSters<<endl;

                                       }
                            }
                   if(gasit_artist==1) cout<<"Stergere album  pentru "<<vartist  <<endl;
                   else cout<<vartist<<"nu exista!"<<endl;

                    c=getch();break;

                  }


          case 24:{

              char s[100];
               string vartist="";
               int gasit=0;
               cout<<"NUMELE Artistului caruia ii afisam  albumele=";cin.getline(s,100,'\n');
               vartist.append(s);
               vector<Artist*>::iterator its;
               for (its=Ar.begin();its!=Ar.end()&&gasit==0;its++)
                  if((*its)->getNume()==vartist)
                              {gasit=1;
                                cout<<"Albumele pentru "<<(*its)->getNume()<<endl;
                               (*its)->afisareAlbume();
                              }
            if(gasit==1) cout<<"Afisare efectuata pentru "<<vartist  <<endl;
            else cout<<vartist<<" nu exista!"<<endl;
            c=getch();break;}



       }
       }while(op!=0);
}
