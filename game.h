#include <conio.h>
#include <iostream>
#include <string.h>
using namespace std;
#ifndef game
#define game


class Mygame{


private:
    int cube_list[4][4]={{0,0,2,4},
                        {2,2,2,0},
                        {0,2,4,2},
                        {2,0,2,2}};
    int cube[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int x_empty[16];
    int y_empty[16];
    int record[2][4]={{0,0,0,0},{0,0,0,0}};
    int max_num=2;

public:
    int x_line[4]={0,0,0,0};
    int y_line[4]={0,0,0,0};


int get_empty(){
            int index=0;
        for(int i=0;i<4;i++){
            for(int y=0;y<4;y++){
                if(cube_list[i][y]==0){
                    x_empty[index]=i;
                    y_empty[index]=y;
                    index+=1;
                }
                else{
                    x_line[i]+=1;
                    y_line[y]+=1;
                }
            };
        };
        if(index==0){
            return 0;
        }
        else{
            return index;
        }
    };


int random_num(){//更新空数组并插入随机数

    int index=get_empty()-1;
    // cout<<"index:"<<index<<endl;
    if(index!=0){
    index=rand()%sizeof(index);
    }
    else{
        system("cls");
        cout<<"you lost"<<endl;
        return 0;
    };
    int z=rand()%99;
    int x=x_empty[index];
    int y=y_empty[index];
    // cout<<x<<":"<<y;
    // cout<<index<<" "<<z<<" "<<x<<" "<<y<<" "<<cube_list[x][y];
    if(z>70){
        if(cube_list[x][y]==0){
        cube_list[x][y]=2;
        };
    }
    else{
        if(cube_list[x][y]==0){
        cube_list[x][y]=4;
        };
    };
    return 1;
};
void copy(){
            memset(record,0,sizeof(record));
            for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cube[j][i]=cube_list[j][i];
                if(cube[j][i]!=0){
                    record[1][j]+=1;
                    record[0][i]+=1;
                }
                };//end of j loop;
            };//end of i loop
    };

void key_input(){
    int a;
    while(1){
    a=getch();
    if(a==27){
        cout<<"quit!!!"<<endl;
        exit(0);
        break;
    }
    else{
    check_input(a);
};

};//end of while
};//end of key_input


    void check_input(int x){
    // int up=119;
    // const int down=115;
    // const int left=97;
    // const int right=100;
    int key=x;
        switch(key){
            case 119 :cout << "\nup"<<endl;up();show();break;
            case 115:cout<< "\ndown"<<endl;down();show();break;
            case 97:cout<<"\nleft"<<endl;left();show();break;
            case 100:cout <<"\nright"<<endl;right();show();break;
            default:cout <<"\nilligle input,please checkout"<<endl;break;
        };
    };

    void show(){
        system("cls");
        cout << "\n  |W,A,S,D|:Control direction !!    |ESC|:quit}  "<< "\n  ";
        // int s=sizeof(max_num);
        // cout<<s<<endl;
        int lost=random_num();
        if(lost==0){
            return;
        }
        copy();
        cout<<"------------------- write by frank----------------------"<<endl;
        for(int i=0;i<4;i++){
            cout<<"\n                  |";
            for(int j=0;j<4;j++){
                cout <<" "<< cube_list[i][j]<<"\t";
            };
        };

    };

void update_max(int x){
    if(x>max_num){
        max_num=x;
    };
};


    void test(){
        for(int i=0;i<4;i++){
        for(int j=3;j>=0;j--){

            };//end of switch

        };//end of j loop
    };//end of i loop;
void turn_down(){
            for(int row = 2; row >= 0; --row)
        {
            for(int crow = row; crow < 4 - 1; ++crow)
            {
                for(int col = 0; col < 4; ++col)
                {
                    if(cube_list[crow + 1][col] == 0)
                    {
                        cube_list[crow + 1][col] = cube_list[crow][col];
                        cube_list[crow][col] = 0;
                    }
                    else
                    {
                        if(cube_list[crow + 1][col] == cube_list[crow][col])
                        {
                            cube_list[crow + 1][col] *= 2;
                            cube_list[crow][col] = 0;
                        }

                    }
                }
            }
        }
copy();
}


    void turn_left(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int y=3-i;
                int x=j;//0,2->1,0
                cube_list[y][x]=cube[j][i];
            };//end of j loop;
        };//end ofi loop
        copy();
    };
void overturn(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int y=3-j;
            int x=i;//0,2->1,0
            cube_list[y][x]=cube[j][i];
        };//end of j loop;
    };//end ofi loop
        copy();
};


    void turn_right(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int y=i;
                int x=3-j;//0,2->2,3
                cube_list[y][x]=cube[j][i];

                };
            };//end of j loop;
        copy();
        };//end ofi loop


void left(){
    turn_left();
    turn_down();
    turn_right();

};


void right(){
        turn_right();
    turn_down();
    turn_left();

};


void up(){
    overturn();
    turn_down();
    overturn();
};


void down(){
    turn_down();
};
};//end of class


#endif
