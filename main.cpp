#include<iostream>
#include<fstream>
#include<stdlib.h>
//#include<windows.h>

using namespace std;

char velha[3][3];
int ix = 0,jy = 0,t22=0,dx = 0;
bool def;

void Inicio(){

   // system("color 7");
    dx = 0;

    for(int i = 0 ;i<3;i++){

        for(int j = 0 ;j<3;j++){

            velha[i][j] =' ';

        }

    }
}

void desenho(){
  for(int i = 0 ;i<3;i++){

            for(int j = 0 ;j<3;j++){

                 if(i==0){//montagem aparencia do jogo
                    cout<<"_";
                }

                if(i==1){
                    cout<<"_";
                }

                if(i==2){
                    cout<<" ";
                }
                cout<<velha[i][j];

                if(i==0){
                    cout<<"_";
                }

                if(i==1){
                    cout<<"_";
                }

                if(i==2){
                    cout<<" ";
                }

                if((j==0)||(j==1)){
                    cout<<"|";
                }
            }
            cout<<"\n";
        }
}

void ContraMedidas(int tipo,int fixo){//defesa ou ataque

    if(tipo == 0){
        t22++;
        for(int i = 0;i<3;i++){

            if(velha[fixo][i] ==' '){
                    ix = fixo;
                    jy = i;
                    def = true;

            }
        }

    }else if(tipo == 1){
        t22++;
        for(int i = 0;i<3;i++){

            if(velha[i][fixo] ==' '){
                    ix = i;
                    jy = fixo;
                    def = true;

            }
        }

    }else if(tipo == 2){
        t22++;
        for(int i = 0;i<3;i++){

            if(velha[i][i] ==' '){
                    ix = i;
                    jy = i;
                    def = true;

            }
        }

    }else if(tipo == 3){
        t22++;
        int i2 = 2;
        for(int i = 0;i<3;i++){

            if(velha[i][i2] ==' '){
                    ix = i;
                    jy = i2;
                    def = true;

            }
            i2--;
        }

    }

}

void analize(){
     int linha = 0,coluna = 0,x=0,o=0,x2=0,o2=0,x3=0,o3=0,x4=0,o4=0;
     bool o1 = false,x1 = false,d1 = false,d2 = false;

     for(int i = 0 ;i<3;i++){

            for(int j = 0 ;j<3;j++){



                if(linha!=i){//confere linh

                    linha = i;
                    x = 0;
                    o = 0;
                }

                if((velha[i][j] == 'X')&&(i == linha)){
                    x++;
                }

                if((velha[i][j] == 'O')&&(i == linha)){
                    o++;
                }
                 if((x==2)&&(!o1)){//prioridade p ataque
                    ContraMedidas(0,linha);//defesa
                }

                if(o==2){//ataque
                    ContraMedidas(0,linha);
                    o1 = true;
                }

                if(coluna!=i){//confere coluna
                    coluna = i;
                    x2 = 0;
                    o2 = 0;
                }

                if((velha[j][i] == 'X')&&(i == coluna)){
                    x2++;
                }

                if((velha[j][i] == 'O')&&(i == coluna)){
                    o2++;
                }

                if((x2 == 2)&&(!x1)){
                    ContraMedidas(1,coluna);
                }

                if(o2 == 2){//ataque
                    ContraMedidas(1,coluna);
                    x1 = true;
                }

                if(i==j){//confere diagonal

                    if(velha[j][i] == 'X'){
                        x3++;
                    }

                    if(velha[j][i] == 'O'){
                        o3++;
                    }

                    if((x3 == 2)&&(!d1)){

                        ContraMedidas(2,0);

                    }

                    if(o3 == 2){

                        ContraMedidas(2,0);
                        d1 = true;
                    }

                    if(i==2){
                        x3 = 0;
                        o3 = 0;
                    }
                }

                if((i+j)==2){//confere diagonal

                    if(velha[j][i] == 'X'){
                        x4++;
                    }

                    if(velha[j][i] == 'O'){
                        o4++;
                    }

                    if((x4 == 2)&&(!d2)){

                        ContraMedidas(3,0);

                    }

                    if(o4 == 2){

                        ContraMedidas(3,0);
                        d2 = true;
                    }

                    if(i==2){
                        x4 = 0;
                        o4 = 0;
                    }
                }
                }
            }
}

void mudacor(int i,int t){

    bool b = true;

   // Sleep(300);

    if(t == 0){

        if(i%2==0){

          //  system("color F0");

        }else{

          //  system("color E1");
        }

        cout<<"u";

    }else{
        if(i%2==0){

          //  system("color F0");

        }else{

          //  system("color C");
        }

        cout<<"#";
    }



}

int Resultado(int x,int o){

    int r = 0;


    if(x == 3){
        r = 1;
    }else if(o == 3){
        r = 2;
    }

    return r;
}

int MostraR(int r){


     int reiniciar = 0,i=0,ok = 0;

        if(r == 1){
            cout<< "\n...........Voce ganhou\n";

            while(i<10){

               // mudacor(i,0);
                i++;
            }

            cout<< "\n...........Fim de jogo\n";
            cout<<"\n......reiniciar..Digite 1 para sim\n";
            cin>>reiniciar;

                if(reiniciar == 1){
                    Inicio();
                    ok = 1;
                }else{

                    ok = 2;
                }
        }else if(r == 2){
            cout<< "\n...........Voce perdeu\n";

            while(i<10){

               // mudacor(i,2);
                i++;
            }

            cout<< "\n...........Fim de jogo\n";
            cout<<"\n......reiniciar..Digite 1 para sim\n";
            cin>>reiniciar;

                if(reiniciar == 1){
                    Inicio();
                    ok = 1;
                }else{

                    ok = 2;
                }

        }else if(r == 3){
            cout<< "\n...........Veia Wins\n";

            while(i<10){

               // mudacor(i,2);
                i++;
            }

            cout<< "\n...........Fim de jogo\n";
            cout<<"\n......reiniciar..Digite 1 para sim\n";
            cin>>reiniciar;

                if(reiniciar == 1){
                    Inicio();
                    ok = 1;
                    system("clear");//apaga tela
                }else{

                    ok = 2;
                }
        }

        return ok;

}



int main(){

    char v;
    int vea = 0,l=0,c=0,x = 0,o = 0,linha = 0,cont = 0,coluna = 0,x2 = 0,o2=0,x3=0,o3=0,x4=0,o4=0,r=0,resp = 0;
    bool ok = true,ganhou = false,verf=true,rep = true;
    int reiniciar = 0;

    cout<<"..............Jogo da velha.............\n";
    
    def = false;
    Inicio();
    desenho();

    while(ok){

       // cout<<"Escolha uma casa\n\n";

            while(rep)
            {

                cout<<"Informe uma posicao para X\n";

                cout<<"Escolha uma linha de 0 a 2\n";
                cin>>l;

                cout<<"Escolha uma coluna de 0 a 2\n";
                cin>>c;

                if(velha[l][c]==' '){

                    velha[l][c] = 'X';
                    rep = false;

                }else{

                    cout<<"\n.........................Escolha outra casa \n";
                }


            }

            rep = true;

            while(verf){

                vea = 0;
                analize();

                if(def){//ataque ou defesa
                    //jy++;
                    velha[ix][jy] = 'O';
                    ix = 0;
                    jy = 0;

                    def = false;
                    verf = false;//sair do while

                    }else{
                    //cout<<ix;
                        if((dx == 1)&&(velha[1][1] == ' ')){

                            velha[1][1] = 'O';
                            verf = false;

                        }else{

                        for(int i = 0 ;i<3;i++){

                            for(int j = 0 ;j<3;j++){

                            if(velha[i][j] ==' '){

                                    l = rand()%10;

                                    if(l%2==0){

                                        l = i;
                                        c = j;
                                        velha[l][c] = 'O';
                                        j = 3;
                                        i = 3;
                                        verf=false;

                                    }

                            }else{

                                 vea++;

                                  if(vea==8){

                                    verf = false;

                                    }

                            }
                        }

                    }
                        }

                }

              }

             verf = true;

        system("clear");//apaga tela


        cout<<"......Jogo da Veia.........\n\n";
        cout<<"...........................\n\n";

        for(int i = 0 ;i<3;i++){

            for(int j = 0 ;j<3;j++){

                 if(i==0){//montagem aparencia do jogo
                    cout<<"_";
                }

                if(i==1){
                    cout<<"_";
                }

                if(i==2){
                    cout<<" ";
                }
                cout<<velha[i][j];

                if(i==0){
                    cout<<"_";
                }

                if(i==1){
                    cout<<"_";
                }

                if(i==2){
                    cout<<" ";
                }

                if((j==0)||(j==1)){
                    cout<<"|";
                }


                if(linha!=i){//confere linh

                    linha = i;
                    x = 0;
                    o = 0;
                }

                if((velha[i][j] == 'X')&&(i == linha)){
                    x++;
                }

                if((velha[i][j] == 'O')&&(i == linha)){
                    o++;
                }

                if(r==0){
                     r = Resultado(x,o);//.......................................................
                }


                if(coluna!=i){//confere coluna
                    coluna = i;
                    x2 = 0;
                    o2 = 0;
                }

                if((velha[j][i] == 'X')&&(i == coluna)){
                    x2++;
                }

                if((velha[j][i] == 'O')&&(i == coluna)){
                    o2++;
                }


               if(r==0){
                     r = Resultado(x2,o2);//.......................................................
                }


                if(i==j){//confere diagonal

                    if(velha[j][i] == 'X'){
                        x3++;
                    }

                    if(velha[j][i] == 'O'){
                        o3++;
                    }


                    if(r==0){
                        r = Resultado(x3,o3);//.......................................................
                    }


                    if(i==2){
                        x3 = 0;
                        o3 = 0;
                    }
                }

                if((i+j)==2){//confere diagonal

                    if(velha[j][i] == 'X'){
                        x4++;
                    }

                    if(velha[j][i] == 'O'){
                        o4++;
                    }

                    if(r==0){
                     r = Resultado(x4,o4);//.......................................................
                    }

                    if(i==2){
                        x4 = 0;
                        o4 = 0;
                    }
                }

            }
            cout<<"\n";
        }
       // cout<<"cc"<<t22<<" "<<ix<<jy;
        cout<<"\n...........................\n\n";

        //cout<<r;
        resp = MostraR(r);
        r = 0;

        cont++;
        dx = cont;
        if(cont == 5){
            cont =0;
            resp = MostraR(3);


        }

        if(resp == 1){
            cont = 0;

        }else if(resp == 2){

            if(ok){
                 ok = false;
            }

            cont = 0;
        }





    }
    return 0;
}
