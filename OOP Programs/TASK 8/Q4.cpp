#include<iostream>
#include<fstream>
using namespace std ;

int ite() {
        ifstream i;string b;float c;
        int a,count=0;
        i.open("participant.dat");
        while(!i.eof()) {
                i >> a >> b >> c ;
                count=count+1;
            }
        i.close();
        return (count);
}
class participant {
    int id;
    string name;
    float score;
    public:
        participant(){}
        participant(int a,string b,float c):id(a),name(b),score(c){}
        void input(){
            ofstream o;
            o.open("participant.dat", ios::app);
            o << id << " " << name << " " << score << endl ;
            o.close();
        }

        void output(){
            participant u[3];
            int a,iD,count=ite(),cc=0; string b; float c;

            ifstream i;
            i.open("participant.dat");
            while(!i.eof()) {
                if(cc==(count-1)) {
                    break ;
                }
                i >> a >> b >> c;
                u[cc]=participant(a,b,c);
                cc=cc+1;
            }
            i.close();
            
            cout << "Enter ID to search: " ;
            cin >> iD; 
            
            for (int ji = 0; ji < 3; ji++) {
                if(iD==u[ji].id) {
                    u[ji].dis();
                    break;
                } else {
                    continue; 
                }
            }
            
        }

        void max() {
            participant u[3];
            int a,iD,count=ite(),cc=0; string b; float c;

            ifstream i;
            i.open("participant.dat");
            while(!i.eof()) {
                if(cc==(count-1)) {
                    break ;
                }
                i >> a >> b >> c;
                u[cc]=participant(a,b,c);
                cc=cc+1;
            }
            i.close();
            
            participant max;
            max.score=u[0].score;
            for(int ji=0;ji<3;ji++) {
                if(max.score<u[ji].score) {
                    max=u[ji];
                } else {
                    max=u[0];
                }
            }
            cout << "\n____________HIGHEST SCORE OUT OF ALL PARTICIPANTS___________\n" ;
            max.dis();
        }

        void dis() {
            cout << "ID: " << id << endl; 
            cout << "Name: " << name << endl ;
            cout << "Score: " << score << endl ;
        }
};

int main(int argc, char const *argv[])
{
    participant a(1,"Hassan",445),b(2,"Sajjad",65),c(3,"Rafay",86);
    a.input();
    b.input();
    c.input();
    a.output();
    a.max();
    remove("participant.dat");
    return 0;
}
