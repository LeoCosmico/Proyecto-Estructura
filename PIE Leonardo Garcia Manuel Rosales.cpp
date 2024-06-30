#include <iostream>
#include <unistd.h>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
using namespace std;

struct planeta{
    string ambiente; 
    int oxigeno;
    planeta *prxpl;
    };
    struct planeta *ap=NULL,*bp=NULL,*ep=NULL;

struct alien{
    string especie;
    int salud;
    int energia;
    string ambiente;
    int oxigeno;
    alien *prxl;
    };
    struct alien *al=NULL,*bl=NULL,*el=NULL;

struct acceso{
    string nacceso;
    int salper;//ataque
    int energas;
    int impred;//defensa
    int salrest;//supervivencia
    int enerest;
    int oxigeno; //adaptacion
    struct acceso *prxacc;
    };
    struct acceso *ac=NULL,*bc=NULL, *ec=NULL;

struct solds{
    string alumno;
    string especie;
    int salud;
    int energia;
    string ambiente;
    struct acceso mochila[5];
    struct solds *prxsol;
    };
    struct solds *as=NULL,*bs=NULL,*es=NULL;
    int sc=0;


int menu_principal(){
    int mp;
    cout<<"-.-.-.-.-.-.-.-.-MENÚ PRINCIPAL INTERGALÁCTICO-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cout<<"1. Gestionar Razas Alienígenas.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-"<<endl;
    cout<<"2. Gestionar Accesorios Ultra-Materiales-.-.-.-.-.-.-..-.-.-.-.-."<<endl;
    cout<<"3. Gestionar Estudiantes e Inventario (Mochilas)-.-.-.-.-.-.-..-."<<endl;
    cout<<"4. Gestionar Atmósferas de Combate (Ambientes)-.-.-.-.-.-.-..-.-."<<endl;
    cout<<"5. Estadísticas de Soldados (Consulta de Equipo)-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"6. Combate por la supervivencia (Batalla/Combate).-.-.-.-.-.-.-.-"<<endl;
    cout<<"7. Nomenclatura de Estadísticas-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cout<<"8. Salir del Juego-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cin>>mp;
    return mp;
}

//(Ambiente)
void agg_amb(string amb, int ox){ //Procedimiento para Insertar Ambientes
    if(ap==NULL){
        ap=new planeta;
        ap->ambiente=amb;
        ap->oxigeno=ox;
        bp=ap;
        ep=ap;}
    else{
        ap=new planeta;
        ap->ambiente=amb;
        ap->oxigeno=ox;
        ep->prxpl=ap;
        ep=ep->prxpl;}
    ep->prxpl=NULL;
}

void mos_amb(){
    struct planeta *cp=NULL;
    cout<<".-.-.-.LISTA DE AMBIENTES.-.-.-."<<endl;
    cp=bp;
    while(cp!=NULL){
        cout<<"Planeta: "<<setw(15)<<left<<cp->ambiente<<setw(5)<<left<<"NOX: "<<cp->oxigeno<<endl;
        cp=cp->prxpl;
    }
}

int busc_amb(string amb){ 
    ap=bp;
    while(ap!=NULL){
        if(ap->ambiente!=amb){
            ap=ap->prxpl;}
        else{
            return 1;}
    }
    return 0;
}

int valid_amb(string amb){
  for (int i = 0; i < 20; i++) {
    if (amb[i]<'A'||amb[i]>'Z') {
        return 1;}
  }
  return 0;
}

void elim_amb(string amb){
    if(busc_amb(amb)==1){
        struct planeta *zp=NULL,*xp=NULL; 
        zp=bp;
        while(zp!=NULL && zp->ambiente!=amb){
            xp=zp;
            zp=zp->prxpl;}
            if(zp==bp){
                bp=bp->prxpl;}
            else{
                xp->prxpl=zp->prxpl;
             delete(zp);
             cout<<"¡Su ambiente ha sido eliminado con éxito!"<<endl;}
        }        

    else{
        cout<<"¡No puedes eliminar un ambiente que no existe!"<<endl;}
}
void crea_amb(){
    int wamb2=0,wamb1=0;
    int ox;
    string amb;
    while(wamb2<1){
        cout<<"Ingresa el nombre de tu ambiente"<<endl;
        cout<<"Tip: Escribe en MAYÚSCULAS"<<endl;
        cin>>amb;
        if(valid_amb(amb)==1){
            while(wamb1<1){
                cout<<"Ingresa el nivel de oxígeno:"<<endl;
                cout<<"Tip: Valores válidos del (90-100)"<<endl;
                cin>>ox;
                if(ox>=90 && ox<=100){
                    agg_amb(amb,ox);
                    cout<<"¡Su ambiente ha sido guardado con éxito!"<<endl;
                    wamb1=1;
                    wamb2=1;}
                else{
                    cout<<"¡Los valores válidos para el oxigeno son del 90-100!"<<endl;
                    cout<<"Intenta de nuevo..."<<endl;}}} 
        else{
            cout<<"Recuerda escribir el nombre de tu ambiente en MAYÚSCULAS"<<endl;
            cout<<"Intenta de nuevo..."<<endl;}
    }
}


void mod_amb(){
    string amb, ambx;
    int oxx;
    int wamo1=0, wamo2=0, wamo3=0;
    while(wamo3<1){
        mos_amb();
        cout<<"Indique el nombre del ambiente que desea modificar:"<<endl;
        cout<<"Tip: Recuerda ingresarlo en MAYÚSCULAS"<<endl;
        cin>>amb;
        if(busc_amb(amb)==1){
            while(wamo2<1){
                cout<<"Indique el nuevo nombre del planeta:"<<endl;
                cin>>ambx;
                if(valid_amb(amb)==1){
                    ap->ambiente=ambx;
                    while(wamo1<1){
                        cout<<"Indique el nuevo nivel de oxígeno de su ambiente:"<<endl;
                        cin>>oxx;
                        if(oxx>=90 && oxx<=100){
                            ap->oxigeno=oxx;
                            cout<<"¡Su ambiente se modificó con éxito!"<<endl;
                            wamo1=1;
                            wamo2=1;
                            wamo3=1;}
                        else{
                            cout<<"Los valores válidos para el oxígeno son del 90-100"<<endl;
                            cout<<"Intenta de nuevo..."<<endl;}
                    }
                }
                else{
                    cout<<"Tip: Recuerda escribirlo en MAYÚSCULAS"<<endl;
                    cout<<"Intenta de nuevo..."<<endl;}
            }
        }
    }      
}

int submenu_amb(){
    int submap;
    cout<<".-.-.OPCIONES DE AMBIENTES.-.-."<<endl;
    cout<<".-.-.-..-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"1. Agregar un Ambiente-.-.-.-.-"<<endl;
    cout<<"2. Modificar un Ambiente-.-.-.-."<<endl;
    cout<<"3. Eliminar un Ambiente-.-.-.-."<<endl;
    cout<<"4. Consultar Ambientes-.-.-.-.-"<<endl;
    cout<<"5. Regresar-.-.-.-.-.-.-.-.-.-."<<endl;
    cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cin>>submap;
    return submap;

}

void default_amb(){
    string ambt;
    int oxt;
    int invambl=0,invambc=0; //Variables que sirven para manejar la lectura del archivo (límite y contador)
    string liamb, bgamb;

    ifstream invamb("amb.inv.txt"); 
    getline(invamb,liamb);
    invambl=stoi(liamb);
    while(invambc!=invambl){
        getline(invamb,liamb);
        bgamb=liamb;             //Variable que sirve para "desechar" -- del archivo.inv
        getline(invamb,liamb);   
        ambt=liamb;              //Extracción de Ambiente
        getline(invamb,liamb);
        oxt=stoi(liamb);         //Extracción de Nivel de Oxígeno
        agg_amb(ambt,oxt);
        invambc=invambc+1;}
    invamb.close();
}

void mos_alien(){
    struct alien *cl;
    cout<<".-.-.-.-.-.-.-.-.-.-.-.-.-.LISTA DE ESPECIES-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cl=bl;
    while(cl!=NULL){
        cout << "Raza: "<<setw(15)<<left<<cl->especie<<" "<<"HP: "<<setw(5)<<left<<cl->salud<<" "<<"SP: "<<setw(5)<<left<<cl->energia<<" "
        <<"Planeta: "<<setw(10)<<left<<cl->ambiente<<"   "<<"NOX: "<<setw(2)<<right<<cl->oxigeno<<" "<<endl;
        cl=cl->prxl;
    }
}
//(Alien)
void ins_alien(string amb, string esp, int hp, int sp, int ox){ //Procedimiento para Insertar Especies
    if(al==NULL){
        al=new alien;
        al->ambiente=amb;
        al->especie=esp;
        al->salud=hp;
        al->energia=sp;
        al->oxigeno=ox;
        bl=al;
        el=al;}
    else{
        al=new alien;
        al->ambiente=amb;
        al->especie=esp;
        al->salud=hp;
        al->energia=sp;
        al->oxigeno=ox;
        el->prxl=al;
        el=el->prxl;}
    el->prxl=NULL;
}    

void default_alien(){
    string ambt, espt;
    int hpt, spt, oxt;
    int invalil=0, invalic=0; //Variables que sirven para manejar la lectura del archivo (límite y contador)
    string liali,bgali;

    ifstream invali("ali.inv.txt"); 
    getline(invali,liali);
    invalil=stoi(liali);
    while(invalic!=invalil){
        getline(invali,liali);  
        bgali=liali;             //Variable que sirve para "desechar" -- del archivo.inv
        getline(invali,liali);
        ambt=liali;              //Extracción de Ambiente 
        getline(invali,liali);
        espt=liali;              //Extracción de Especies
        getline(invali,liali);
        hpt=stoi(liali);         //Extracción de Salud
        getline(invali,liali);
        spt=stoi(liali);         //Extracción de Energía
        getline(invali,liali);
        oxt=stoi(liali);         //Extracción de Nivel de Oxígeno
        ins_alien(ambt,espt,hpt,spt,oxt);
        invalic=invalic+1;}
    invali.close();
}

int busc_alien(string esp){
    al=bl;
    while(al!=NULL){
        if(al->especie!=esp){
            al=al->prxl;}
        else{
            return 1;}
    }
    return 0;
}

int valid_hsp(int hp, int sp){
    if(hp>100 || sp>100){
        return 0;}
    else{
        return 1;}
}

void crea_alien(){
    int wal1=0,wal2=0;
    string amb, esp;
    int hp=0,sp=0,ox=0;    
    while(wal2<1){
        cout<<"Selecciona el planeta de tu nueva especie:"<<endl;
        cout<<"Tip: Recuerda escribir todo en MAYÚSCULAS"<<endl;
        mos_amb();
        cin>>amb;
        if(busc_amb(amb)==1){
            amb=ap->ambiente;
            ox=ap->oxigeno;
            cout<<"Dale nombre a la nueva raza espacial:"<<endl;
            cin>>esp;
            while(wal1<1){
                cout<<"Indica su salud: (1-100)"<<endl;
                cin>>hp;
                cout<<"Indica su energia: (1-100)"<<endl;
                cin>>sp;
                if(valid_hsp(hp,sp)==1){
                    ins_alien(amb,esp, hp,sp,ox);
                        cout<<"¡Su nueva especie fue registrada con éxito!"<<endl;
                            wal1=1;
                            wal2=1;}
                else{
                    cout<<"¡Uno o ambos valores ingresados, exceden el límite establecido!"<<endl;
                    cout<<"Intente de nuevo..."<<endl;}
            }
        }
            
        else{
            cout<<"¡El ambiente seleccionado no existe o está ingresado erróneamente!"<<endl;
            cout<<"Intente de nuevo..."<<endl;}
    }

}


void mod_alien(string esp){
    string espx, ambx;
    int hpx, spx, wal3=0, wal4=0;
    if(busc_alien(esp)==1){
        while(wal4<1){
            cout<<"Selecciona el nuevo planeta para tu especie:"<<endl;
            cout<<"Tip: Recuerda escribir todo en MAYÚSCULAS"<<endl;
            mos_amb();
            cin>>ambx;
            if(busc_amb(ambx)==1){
                al->ambiente=ap->ambiente;
                al->oxigeno=ap->oxigeno;
                cout<<"Indique el nuevo nombre de la especie:"<<endl;
                cin>>espx;
                al->especie=espx;
                while(wal3<1){
                cout<<"Indique la nueva cantidad de salud de la especie (1-100):"<<endl;
                cin>>hpx;
                cout<<"Indique la nueva cantidad de energía de la especie (1-100):"<<endl;
                cin>>spx;
                if(valid_hsp(hpx, spx)==1){
                    al->energia=spx;
                    al->salud=hpx;
                    cout<<"¡Su especie ha sido modificada con éxito!"<<endl;
                    wal3=1;
                    wal4=1;}
                else{
                    cout<<"¡El valor ingresado, excede el límite establecido!"<<endl;
                    cout<<"Intente de nuevo..."<<endl;}}
            }
            else{
                cout<<"¡La especie seleccionada no existe o está ingresada erróneamente!"<<endl;
                cout<<"Intente de nuevo..."<<endl;}
        }
    }
}
void elim_alien(string esp){
    if(busc_alien(esp)==1){
        struct alien *zl=NULL,*xl=NULL; 
        zl=bl;
        while (zl!=NULL && zl->especie!=esp){
            xl=zl;
            zl=zl->prxl;}
            if (zl==bl){
                bl=bl->prxl;}
            else{
                xl->prxl=zl->prxl;
             delete (zl);
             cout<<"¡Su especie ha sido eliminada con exito!"<<endl;}
        }         

    else{
        cout<<"¡No puedes eliminar una especie que no existe!"<<endl;}
}

int submenu_aliens(){
    int submal;
    cout<<".-.-.-.-.-OPCIONES DE ESPECIES.-.-.-.-.-.-"<<endl;
    cout<<".-.-.-..-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cout<<"1. Agregar una Especie-..-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"2. Modificar una Especie.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"3. Eliminar una Especie-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"4. Mostrar Especies.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cout<<"5. Regresar-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<".-.-.-..-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cin>>submal;
    return submal;

}

//(Accesorios)

int submenu_acceso(){
    int submac;
    cout<<"-.-.-GESTIÓN DE ACCESORIOS-.-.-.-"<<endl;
    cout<<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cout<<"1. Crear Nuevo Accesorio-.-.-.-.-"<<endl;
    cout<<"2. Modificar Accesorio.-.-.-.-.-."<<endl;
    cout<<"3. Eliminar Accesorio.-.-.-.-.-.-"<<endl;
    cout<<"4. Mostrar Accesorios-.-.-.-.-.-."<<endl;
    cout<<"5. Regresar-.-.-.-.-.-.-..-.-.-.-"<<endl;
    cout<<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cin>>submac;
    return submac;
}

int submenu_accrear(){
    int submacr;
    cout<<".-.-.-..-.-.-.-.-.-CREACIÓN/MODIFICACIÓN DE ACCESORIOS-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cout<<"1. Accesorio de Ataque (Consume energía)-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"2. Accesorio de Defensa (Se usan sólo una vez).-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cout<<"3. Accesorio de Supervivencia (Regeneran salud y/o energía).-.-.-.-.-.-.-.-"<<endl;
    cout<<"4. Accesorio de Adaptación (Te permite combatir en distintos ambientes)-.-."<<endl;
    cout<<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cin>>submacr;
    return submacr;
}

void ins_acceso(string nac, int hpp, int spg, int dr, int hpr, int spr, int ox){ //Procedimiento para Insertar Accesorios
    if(ac==NULL){
        ac=new acceso;
        ac->nacceso=nac;
        ac->salper=hpp;
        ac->energas=spg;
        ac->impred=dr;
        ac->salrest=hpr;
        ac->enerest=spr;
        ac->oxigeno=ox;
        bc=ac;
        ec=ac;}
    else{
        ac=new acceso;
        ac->nacceso=nac;
        ac->salper=hpp;
        ac->energas=spg;
        ac->impred=dr;
        ac->salrest=hpr;
        ac->enerest=spr;
        ac->oxigeno=ox;
        ec->prxacc=ac;
        ec=ec->prxacc;}
    ec->prxacc=NULL;
}

void crea_acceso(){
    string nac;
    int hpp,spg,dr,hpr,spr,ox;
    int submacr, wac1=0, wac2=0, wac3=0, wac4=0;
    cout<<"¿Qué tipo de accesorio desea crear?"<<endl;
    submacr=submenu_accrear();
    switch(submacr){
        case 1:
        cout<<"Dale nombre a tu nueva arma de destrucción:"<<endl;
        cin>>nac;
        while(wac1<1){
            cout<<"(Valores válidos del 0-100)"<<endl;
            cout<<"Indique la energía que consumirá su accesorio de ataque:"<<endl;
            cin>>spg;
            cout<<"Especifique la fuerza que tendrá su nuevo accesorio de ataque:"<<endl;
            cin>>hpp;
            if(spg>100||hpp>100){
                cout<<"¡Uno o ambos valores exceden el límite establecido!"<<endl;
                cout<<"Por favor intenta de nuevo..."<<endl;
            }
            else{
            //Se convierten el resto de valores a "0" para volverlo únicamente de ataque.
            dr=0, hpr=0, spr=0,ox=0;
            ins_acceso(nac, hpp, spg, dr, hpr, spr, ox);
            cout<<"¡Su accesorio fue creado con éxito!"<<endl;
            wac1=1;
            }
        }
        break;
        
        case 2:
        cout<<"Dale nombre a tu nuevo componente defensivo:"<<endl;
        cin>>nac;
        while(wac2<0){
            cout<<"Indique el porcentaje de dolor que reducirá tu artefacto:"<<endl;
            cout<<"(Valores válidos del 0-70)"<<endl;
            cin>>dr;
            if(dr>70){
                cout<<"El valor excede el límite establecido:"<<endl;
                cout<<"Por favor intenta de nuevo..."<<endl;}
            else{
                //Se convierten el resto de valores a "0" para volverlo únicamente de defensa.
                hpp=0,spg=0,hpr=0,spr=0,ox=0;
                ins_acceso(nac, hpp, spg, dr, hpr, spr, ox);
                cout<<"¡Su accesorio fue creado con éxito!"<<endl;
                wac2=1;}
        }
        break;
        
        case 3:
        cout<<"Dale nombre a tu futuro botiquín de primeros auxilios:"<<endl;
        cout<<"(Valores válidos del 0-60)"<<endl;
        cin>>nac;
        while(wac3){
            cout<<"Indique que tantos puntos de salud restaurará: (puedes poner 0)"<<endl;
            cin>>hpr;
            cout<<"Indique que tantos puntos de energía restaurará: (puedes poner 0)"<<endl;
            cin>>spr;
            if(hpr>60||spr>60){
                cout<<"¡Uno o ambos valores exceden el límite establecido!"<<endl;
                cout<<"Por favor intenta de nuevo..."<<endl;}
            else{    
                //Se convierten el resto de valores a "0" para volverlo únicamente de supervivencia.
                hpp=0,spg=0,dr=0,ox=0;
                ins_acceso(nac, hpp, spg, dr, hpr, spr, ox);
                cout<<"¡Su accesorio fue creado con éxito!"<<endl;
                wac3=1;}
        }
        break;

        case 4:
        cout<<"Dale nombre a tu primordial requisito para no morir fuera de tu planeta:"<<endl;
        cin>>nac;
        mos_amb();
        while(wac4<1){
            cout<<"Para adaptarte al ambiente que deseas, ingresa su nivel de oxígeno (NOX):"<<endl;
            cout<<"(Valores válidos del 90-100)"<<endl;
            cin>>ox;
            if(ox<90 || ox>100){
                cout<<"¡El valor excede (o es inferior) al límite establecido!"<<endl;
                cout<<"Por favor intenta de nuevo..."<<endl;}
            else{
                //Se convierten el resto de valores a "0" para volverlo únicamente de adaptación.
                hpp=0,spg=0,dr=0,hpr=0,spr=0;
                ins_acceso(nac, hpp, spg, dr, hpr, spr, ox);
                cout<<"¡Su accesorio fue creado con éxito!"<<endl;
                wac4=1;}
        }
        break;
        }
        

}

void mos_acceso(){
    struct acceso *cc=NULL;
    cout<<".-.-.-.-.-.-.-.-.-.-.-.-.-.LISTA DE ACCESORIOS.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cc=bc;
    while(cc!=NULL){
        cout<<"Accesorio: "<<setw(12)<<left<<cc->nacceso<<"   "<<setw(3)<<left<<"DI: "<<setw(3)<<left<<cc->salper<<" "<<"EG: "<<setw(3)<<left<<cc->energas<<" "<<"DR: "<<setw(4)<<left<<cc->impred<<" "<<
        "SR: "<<setw(3)<<left<<cc->salrest<<" "<<"ER: "<<setw(3)<<left<<cc->enerest<<" "<<"NOX: "<<setw(3)<<left<<cc->oxigeno<<" "<<endl;
        cc=cc->prxacc;
    }
}


int busc_acceso(string nac){
    ac=bc;
    while(ac!=NULL){
        if(ac->nacceso!=nac){
            ac=ac->prxacc;}
        else{
            return 1;}
    }
    return 0;
}


void mod_acceso(string nac){
    string nacx;
    int hppx,spgx,drx,hprx,sprx,oxx,submacr;
    int wacm1=0, wacm2=0, wacm3=0, wacm4=0;
    if(busc_acceso(nac)==1){
        cout<<"¿Deseas convertir tu accesorio a un tipo específico? (supervivencia, adaptación,etc...)"<<endl;
        submacr=submenu_accrear();
        switch(submacr){
            case 1:
            cout<<"Dale nombre a tu renovada arma de destrucción:"<<endl;
            cin>>nacx;
            ac->nacceso=nacx;
            while(wacm1<1){
                cout<<"(Valores válidos del 0-100)"<<endl;
                cout<<"Indique la energía que consumirá su accesorio de ataque:"<<endl;
                cin>>spgx;
                cout<<"Indique el impacto que hará su accesorio de ataque:"<<endl;
                cin>>hppx;
                if(spgx>100||hppx>100){
                    cout<<"¡Uno o ambos valores exceden el límite establecido!"<<endl;
                    cout<<"Por favor intenta de nuevo..."<<endl;}
                else{
                    ac->energas=spgx;
                    ac->salper=hppx;
                    //Se convierten el resto de valores a "0" para volverlo únicamente de ataque.
                    drx=0, hprx=0, sprx=0,oxx=0;
                    ac->impred=drx;
                    ac->salrest=hprx;
                    ac->enerest=sprx;
                    ac->oxigeno=oxx;
                    cout<<"¡Su accesorio fue modificado con éxito!"<<endl;
                    wacm1=1;}    
            break;
            case 2:
            cout<<"Dale nombre a tu nuevo componente defensivo"<<endl;
            cin>>nacx;
            ac->nacceso=nacx;
            while(wacm2<1){
                cout<<"Indica el porcentaje de dolor que reducirá tu artefacto:"<<endl;
                cout<<"(Valores válidos del 0-70)"<<endl;
                cin>>drx;
                if(drx>70){
                    cout<<"¡El valor excede el límite establecido!"<<endl;
                    cout<<"Por favor intenta de nuevo..."<<endl;}
                else{
                    ac->impred=drx;
                    //Se convierten el resto de valores a "0" para volverlo únicamente de defensa.
                    hppx=0,spgx=0,hprx=0,sprx=0,oxx=0;
                    ac->salper=hppx;
                    ac->energas=spgx;
                    ac->salrest=hprx;
                    ac->enerest=sprx;
                    ac->oxigeno=oxx;
                    cout<<"¡Su accesorio fue modificado con éxito!"<<endl;
                    wacm2=1;}    
            }
            break;

            case 3:
            cout<<"Dale nombre a tu futuro botiquín de primeros auxilios:"<<endl;
            cin>>nacx;
            ac->nacceso=nacx;
            while(wacm3<1){
                cout<<"(Valores válidos del 0-60)"<<endl;
                cout<<"Indique que tantos puntos de salud restaurará: (puedes poner 0)"<<endl;
                cin>>hprx;
                cout<<"Indique que tantos puntos de energía restaurará: (puedes poner 0)"<<endl;
                cin>>sprx;
                if(hprx>60||sprx>60){
                    cout<<"¡Uno o ambos valores exceden el límite establecido!"<<endl;
                    cout<<"Por favor intenta de nuevo..."<<endl;}
                else{
                    ac->salrest=hprx;
                    ac->enerest=sprx;
                    //Se convierten el resto de valores a "0" para volverlo únicamente de supervivencia.
                    hppx=0,spgx=0,drx=0,oxx=0;
                    ac->salper=hppx;
                    ac->energas=spgx;
                    ac->impred=drx;
                    ac->oxigeno=oxx;
                    cout<<"¡Su accesorio fue modificado con éxito!"<<endl;
                    wacm3=1;}
                
            }
            break;

            case 4:
            cout<<"Dale nombre a tu primordial requisito para no morir fuera de tu planeta:"<<endl;
            cin>>nacx;
            ac->nacceso=nacx;
            mos_amb();
            while(wacm4<1){
                cout<<"Para adaptarte al ambiente que deseas, ingresa su nivel de oxígeno (NOX):"<<endl;
                cin>>oxx;
                if(oxx<90 || oxx>100){
                    cout<<"¡El valor excede (o es inferior) al límite establecido!"<<endl;
                    cout<<"Por favor intenta de nuevo..."<<endl;}
                else{
                    ac->oxigeno=oxx;
                    //Se convierten el resto de valores a "0" para volverlo únicamente de adaptación.
                    hppx=0,spgx=0,drx=0,hprx=0,sprx=0;
                    ac->salper=hppx;
                    ac->energas=spgx;
                    ac->impred=drx;
                    ac->salrest=hprx;
                    ac->enerest=sprx;
                    cout<<"¡Su accesorio fue modificado con éxito!"<<endl;
                    wacm4=1;}
            }
            break;
            }
        }
    }    

    else{
        cout<<"¡No puedes modificar un accesorio que no existe!"<<endl;
        cout<<"Tip: Recuerda ingresar su nombre correctamente"<<endl;}
       
}

void elim_acceso(string nac){
    if(busc_acceso(nac)==1){
        struct acceso *zc=NULL,*xc=NULL; 
        zc=bc;
        while (zc!=NULL && zc->nacceso!=nac){
            xc=zc;
            zc=zc->prxacc;}
            if (zc==bc){
                bc=bc->prxacc;}
            else{
                xc->prxacc=zc->prxacc;
             delete(zc);
             cout<<"¡Su accesorio fue eliminado con éxito!"<<endl;}
        }      

    else{
        cout<<"¡No puedes eliminar un accesorio que no existe!"<<endl;}
}

void default_acceso(){
    string nact;
    int hppt, spgt, drt, hprt, sprt, oxt;
    int invaccl=0, invaccc=0; //Variables que sirven para manejar la lectura del archivo (límite y contador)
    string liacc,bgacc;

    ifstream invacc("acc.inv.txt"); 
    getline(invacc,liacc);
    invaccl=stoi(liacc);
    while(invaccc!=invaccl){
        getline(invacc,liacc);
        bgacc=liacc;                //Variable que sirve para "desechar" -- del archivo.inv
        getline(invacc,liacc);
        nact=liacc;
        getline(invacc,liacc);         
        hppt=stoi(liacc);           //Extracción de Estadísticas de Ataque
        getline(invacc,liacc);
        spgt=stoi(liacc);
        getline(invacc,liacc);         
        drt=stoi(liacc);            //Extracción de Estadísticas de Defensa
        getline(invacc,liacc);         
        hprt=stoi(liacc);           //Extracción de Estadísticas de Supervivencia
        getline(invacc,liacc);
        sprt=stoi(liacc);
        getline(invacc,liacc);         
        oxt=stoi(liacc);            //Extracción de Estadísticas de Adaptación
        ins_acceso(nact,hppt,spgt,drt,hprt,sprt,oxt);
        invaccc=invaccc+1;}
        invacc.close();
}

//(Soldados/Estudiantes)
int submenu_solds(){
    int submsol;
    cout<<".-.-.-..-.-.-OPCIONES DE SOLDADOS.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<".-.-.-..-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"1. Agregar un Soldado-..-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"2. Modificar un Soldado.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"3. Eliminar un Soldado-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"4. Agregar Objetos a la mochila de un soldado.-.-.-"<<endl;
    cout<<"5. Modificar un Slot de la mochila de un soldado.-."<<endl;
    cout<<"6. Eliminar un Slot de la mochila de un soldado.-.-"<<endl;
    cout<<"7. Regresar-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cout<<".-.-.-..-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cin>>submsol;
    return submsol;

}

void agg_solds(){
    string aluma,esp;
    cout<<"Escoja la raza del soldado que desea agregar:"<<endl;
    cout<<"Tip: Escribe tal cual el nombre de la raza"<<endl;
    mos_alien();
    cin>>esp;
    if(busc_alien(esp)==1){
        if(as==NULL){
            as=new solds;
            as->especie=al->especie;
            as->salud=al->salud;
            as->energia=al->energia;
            as->ambiente=al->ambiente;
            bs=as;
            es=as;}
        else{
            as=new solds;
            as->especie=al->especie;
            as->salud=al->salud;
            as->energia=al->energia;
            as->ambiente=al->ambiente;
            es->prxsol=as;
            es=es->prxsol;}
        cout<<"Ingresa el nombre del alumno:"<<endl;
        cin>>aluma;
        cout<<"¡Su alumno se ha registrado con éxito!"<<endl;
        sc=sc+1;
        as->alumno=aluma;
        es->prxsol=NULL;}
    else{
        cout<<"Por favor... Escribe correctamente el nombre sin ignorar MAYÚSCULAS"<<endl;
        cout<<"(También puede ser que no exista la raza de la que hablas...)"<<endl;
        submenu_solds();
    }
}

int busc_solds(string aluma){
    as=bs;
    while(as!=NULL){
        if(as->alumno!=aluma){
            as=as->prxsol;}
        else{
            return 1;}
    }
    return 0;
}

void mos_solds(){
    struct solds *cs=NULL;
    cout<<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.LISTA DE ESTUDIANTES.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cs=bs;
    while(cs!=NULL){
        cout<<setw(15)<<left<<cs->alumno<<setw(5)<<left<<"Raza: "<<setw(15)<<left<<cs->especie<<" "<<"HP: "<<setw(5)<<left<<cs->salud<<" "<<
        "SP: "<<setw(5)<<left<<cs->energia<<" "<<"Planeta: "<<setw(10)<<left<<cs->ambiente<<endl;
        cs=cs->prxsol;
    }
}


void mod_solds(string alumn){
    string alumnx,esp;
    int submsol;
    if(busc_solds(alumn)==1){
        cout<<"¿Qué deseas hacer con tu estudiante/soldado intergaláctico?"<<endl;
        cout<<"1. Modificar su nombre"<<endl;
        cout<<"2. Cambiarlo de raza"<<endl;
        cin>>submsol;
        switch(submsol){
            case 1:
            cout<<"Renombra a tu miembro del 'Comando Estelar': (Referencia Pixar)"<<endl;
            cin>>alumnx;
            as->alumno=alumnx;
            cout<<"¡Se renombró su alumno con éxito!"<<endl;
            break;


            case 2:
            cout<<"Escoja la nueva raza de su soldado:"<<endl;
            cout<<"Tip: Escribe tal cual el nombre de la raza"<<endl;
            mos_alien();
            cin>>esp;
            if(busc_alien(esp)==1){
                as->especie=al->especie;
                as->salud=al->salud;
                as->energia=al->energia;
                as->ambiente=al->ambiente;}
            else{
                cout<<"Por favor... Escribe correctamente el nombre sin ignorar MAYÚSCULAS"<<endl;
                cout<<"(También puede ser que no exista la raza de la que hablas...)"<<endl;
                submenu_solds();
            }
            break;    
        }            
    }
}

void elim_solds(string alumn){
    if(busc_solds(alumn)==1){
        struct solds *zs=NULL,*xs=NULL; 
        zs=bs;
        while(zs!=NULL && zs->alumno!=alumn){
            xs=zs;
            zs=zs->prxsol;}
            if (zs==bs){
                bs=bs->prxsol;}
            else{
                xs->prxsol=zs->prxsol;
             delete(zs);
             cout<<"¡Su soldado fue eliminado con éxito!"<<endl;
             sc=sc-1;}
        }      

    else{
        cout<<"¡No puedes eliminar un soldado inexistente!"<<endl;}
}

void agg_mochila(string alumn){
    if(busc_solds(alumn)==1){
        int gsm=0,is=0;
        string nactx;
        while(gsm<5){
            mos_acceso();
            cout<<"Escribe el accesorio que deseas asignar al compartimiento ["<<is<<"] de tu soldado:"<<endl;
            cout<<"Tip: Recuerda escribirlo correctamente y en MAYÚSCULAS"<<endl;
            cin>>nactx;
            if(busc_acceso(nactx)==1){
                as->mochila[is].nacceso=ac->nacceso;
                as->mochila[is].salper=ac->salper;
                as->mochila[is].energas=ac->energas;
                as->mochila[is].impred=ac->impred;
                as->mochila[is].salrest=ac->salrest;
                as->mochila[is].enerest=ac->enerest;
                as->mochila[is].oxigeno=ac->oxigeno;
                is=is+1;
                gsm=gsm+1;}
            else{
                cout<<"¡No puedes agregarle accesorios que no existen!"<<endl;
                cout<<"Recuerda escribirlo correctamente en MAYÚSCULAS"<<endl;}
        }
        cout<<"¡La mochila de su soldado se ha llenado con éxito!"<<endl;
    
}

}

void mod_mochila(string alumn){
    if(busc_solds(alumn)==1){
        int is, msm1=0, msm2=0;
        string nactx;
        while(msm2<1){
        cout<<"Escoja el slot que desea modificar de la mochila:"<<endl;
        cout<<"(Valores válidos del 0-4)"<<endl;
        cin>>is;
            if(is<0 && is>4){
                cout<<"CIFRA INVÁLIDA..."<<endl;}
            else{
                while(msm1<1){
                    cout<<"¿Con qué accesorio desea reemplazarlo?"<<endl;
                    mos_acceso();
                    cout<<"Recuerde ingresar en MAYÚSCULAS y escribirlo correctamente"<<endl;
                    cin>>nactx;
                    if(busc_acceso(nactx)==1){
                        as->mochila[is].nacceso=ac->nacceso;
                        as->mochila[is].salper=ac->salper;
                        as->mochila[is].energas=ac->energas;
                        as->mochila[is].impred=ac->impred;
                        as->mochila[is].salrest=ac->salrest;
                        as->mochila[is].enerest=ac->enerest;
                        as->mochila[is].oxigeno=ac->oxigeno;
                        cout<<"¡El slot de su mochila se ha modificado con éxito!"<<endl;
                        msm1=1;
                        msm2=1;}
                    else{
                        cout<<"¡No puedes cambiar el contenido de un slot, por uno que no exista!"<<endl;
                        cout<<"Verifica la lista de accesorios y escribe en MAYÚSCULAS"<<endl;} 
                }
            }
        }                   

    }
}


void elim_mochila(string alumn){
    if(busc_solds(alumn)==1){
        int is,esm=0;
        string nactx;
        while(esm<1){
            cout<<"Escoja el slot que desea eliminar de su mochila:"<<endl;
            cout<<"(Valores válidos del 0-4)"<<endl;
            cin>>is;
            if(is>4){
                cout<<"CIFRA INVÁLIDA..."<<endl;}
            else{
                as->mochila[is].nacceso="";
                as->mochila[is].salper=0;
                as->mochila[is].energas=0;
                as->mochila[is].impred=0;
                as->mochila[is].salrest=0;
                as->mochila[is].enerest=0;
                as->mochila[is].oxigeno=0;
                cout<<"¡Se ha eliminado su slot de mochila con éxito!"<<endl;
                esm=1;}
        }
    }
}
//(Consulta de Equipo)
void cons_eq(){
    struct solds *csl=NULL;
    if(as==NULL){
        cout<<"¡¡UUUPPPSSS!!"<<endl;
        cout<<"Parece que no hay soldados registrados..."<<endl;
        cout<<"(Regresa luego de crear al menos [1] soldado)"<<endl;}
    else{
        cout<<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.ESTADÍSTICAS DE SOLDADOS (CONSULTA DE EQUIPO).-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
        csl=bs;
        while(csl!=NULL){
            cout<<setw(11)<<left<<csl->alumno<<"   "<<"HP: "<<setw(5)<<left<<csl->salud<<" "<<"SP: "<<setw(7)<<left<<csl->energia<<" "<<"Raza: "<<setw(7)<<left<<csl->especie<<" "<<"Planeta: "<<setw(5)<<left<<csl->ambiente<<" "<<endl;
            cout<<"SM(0): ["<<setw(5)<<left<<csl->mochila[0].nacceso<<"] "<<"SM(1): ["<<setw(5)<<left<<csl->mochila[1].nacceso<<"] "<<"SM(2): ["<<setw(5)<<left<<csl->mochila[2].nacceso<<"] "<<"SM(3): ["<<setw(5)<<left<<csl->mochila[3].nacceso<<"] "<<"SM(4): ["<<setw(5)<<right<<csl->mochila[4].nacceso<<"]"<<endl;
            csl=csl->prxsol;}}
}

//(Modo Batalla)
struct humanos{
    struct solds humalum; //dato tipo solds
    int topesalud;
    int topenergia;
    int barrera;
    struct humanos *prxh;
    };
struct humanos *ah=NULL, *bh=NULL, *eh=NULL, *hsf=NULL;

struct andros{
    struct solds andralum; //dato tipo solds
    int topesalud;
    int topenergia;
    int barrera;
    struct andros *prxd;
    };
struct andros *ad=NULL, *bd=NULL, *ed=NULL, *dsf=NULL;

//NOTA: Estas funciones solo "hacen", no muestran "diálogos"

void ins_hum(string alumno, string especie, int salud, int energia, string ambiente, acceso mochila[]){ //Procedimiento para Insertar alumnos de fidelidad humana.
    if(ah==NULL){
        ah=new humanos;
        ah->humalum.alumno=alumno;
        ah->humalum.especie=especie;
        ah->humalum.salud=salud;
        ah->humalum.energia=energia;
        ah->humalum.ambiente=ambiente;
        ah->humalum.mochila[0].nacceso=mochila[0].nacceso;
        ah->humalum.mochila[0].salper=mochila[0].salper;
        ah->humalum.mochila[0].energas=mochila[0].energas;
        ah->humalum.mochila[0].impred=mochila[0].impred;
        ah->humalum.mochila[0].salrest=mochila[0].salrest;
        ah->humalum.mochila[0].enerest=mochila[0].enerest;
        ah->humalum.mochila[0].enerest=mochila[0].oxigeno;
        ah->humalum.mochila[1].nacceso=mochila[1].nacceso;
        ah->humalum.mochila[1].salper=mochila[1].salper;
        ah->humalum.mochila[1].energas=mochila[1].energas;
        ah->humalum.mochila[1].impred=mochila[1].impred;
        ah->humalum.mochila[1].salrest=mochila[1].salrest;
        ah->humalum.mochila[1].enerest=mochila[1].enerest;
        ah->humalum.mochila[1].enerest=mochila[1].oxigeno;
        ah->humalum.mochila[2].nacceso=mochila[2].nacceso;
        ah->humalum.mochila[2].salper=mochila[2].salper;
        ah->humalum.mochila[2].energas=mochila[2].energas;
        ah->humalum.mochila[2].impred=mochila[2].impred;
        ah->humalum.mochila[2].salrest=mochila[2].salrest;
        ah->humalum.mochila[2].enerest=mochila[2].enerest;
        ah->humalum.mochila[2].enerest=mochila[2].oxigeno;
        ah->humalum.mochila[3].nacceso=mochila[3].nacceso;
        ah->humalum.mochila[3].salper=mochila[3].salper;
        ah->humalum.mochila[3].energas=mochila[3].energas;
        ah->humalum.mochila[3].impred=mochila[3].impred;
        ah->humalum.mochila[3].salrest=mochila[3].salrest;
        ah->humalum.mochila[3].enerest=mochila[3].enerest;
        ah->humalum.mochila[3].enerest=mochila[3].oxigeno;
        ah->humalum.mochila[4].nacceso=mochila[4].nacceso;
        ah->humalum.mochila[4].salper=mochila[4].salper;
        ah->humalum.mochila[4].energas=mochila[4].energas;
        ah->humalum.mochila[4].impred=mochila[4].impred;
        ah->humalum.mochila[4].salrest=mochila[4].salrest;
        ah->humalum.mochila[4].enerest=mochila[4].enerest;
        ah->humalum.mochila[4].enerest=mochila[4].oxigeno;
        ah->topesalud=salud;
        ah->topenergia=energia;
        bh=ah;
        eh=ah;}
    else{
        ah=new humanos;
        ah->humalum.alumno=alumno;
        ah->humalum.especie=especie;
        ah->humalum.salud=salud;
        ah->humalum.energia=energia;
        ah->humalum.ambiente=ambiente;
        ah->humalum.mochila[0].nacceso=mochila[0].nacceso;
        ah->humalum.mochila[0].salper=mochila[0].salper;
        ah->humalum.mochila[0].energas=mochila[0].energas;
        ah->humalum.mochila[0].impred=mochila[0].impred;
        ah->humalum.mochila[0].salrest=mochila[0].salrest;
        ah->humalum.mochila[0].enerest=mochila[0].enerest;
        ah->humalum.mochila[0].enerest=mochila[0].oxigeno;
        ah->humalum.mochila[1].nacceso=mochila[1].nacceso;
        ah->humalum.mochila[1].salper=mochila[1].salper;
        ah->humalum.mochila[1].energas=mochila[1].energas;
        ah->humalum.mochila[1].impred=mochila[1].impred;
        ah->humalum.mochila[1].salrest=mochila[1].salrest;
        ah->humalum.mochila[1].enerest=mochila[1].enerest;
        ah->humalum.mochila[1].enerest=mochila[1].oxigeno;
        ah->humalum.mochila[2].nacceso=mochila[2].nacceso;
        ah->humalum.mochila[2].salper=mochila[2].salper;
        ah->humalum.mochila[2].energas=mochila[2].energas;
        ah->humalum.mochila[2].impred=mochila[2].impred;
        ah->humalum.mochila[2].salrest=mochila[2].salrest;
        ah->humalum.mochila[2].enerest=mochila[2].enerest;
        ah->humalum.mochila[2].enerest=mochila[2].oxigeno;
        ah->humalum.mochila[3].nacceso=mochila[3].nacceso;
        ah->humalum.mochila[3].salper=mochila[3].salper;
        ah->humalum.mochila[3].energas=mochila[3].energas;
        ah->humalum.mochila[3].impred=mochila[3].impred;
        ah->humalum.mochila[3].salrest=mochila[3].salrest;
        ah->humalum.mochila[3].enerest=mochila[3].enerest;
        ah->humalum.mochila[3].enerest=mochila[3].oxigeno;
        ah->humalum.mochila[4].nacceso=mochila[4].nacceso;
        ah->humalum.mochila[4].salper=mochila[4].salper;
        ah->humalum.mochila[4].energas=mochila[4].energas;
        ah->humalum.mochila[4].impred=mochila[4].impred;
        ah->humalum.mochila[4].salrest=mochila[4].salrest;
        ah->humalum.mochila[4].enerest=mochila[4].enerest;
        ah->humalum.mochila[4].enerest=mochila[4].oxigeno;
        eh->prxh=ah;
        eh=eh->prxh;}
    eh->prxh=NULL;
}

int busc_hum(string alumno){ 
    ah=bh;
    while(ah!=NULL){
        if(ah->humalum.alumno!=alumno){
            ah=ah->prxh;}
        else{
            return 1;}
    }
    return 0;
}

void mort_hum(string alumno){
    struct humanos *zh=NULL,*xh=NULL; 
    zh=bh;
    while(zh!=NULL && zh->humalum.alumno!=alumno){
        xh=zh;
        zh=zh->prxh;}
        if(zh==bh){
            bh=bh->prxh;}
        else{
            xh->prxh=zh->prxh;
            delete(zh);}
}

void eq_hum(){
    struct humanos *ch=NULL;
    cout<<".-.-.-.-.-.-.-.-.-.-.-.-.ESTADÍSTICAS DE HUMANOS (CONSULTA DE EQUIPO).-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
        ch=bh;
        while(ch!=NULL){
            cout<<setw(11)<<left<<ch->humalum.alumno<<"   "<<"HP: "<<setw(5)<<left<<ch->humalum.salud<<" "<<"SP: "<<setw(7)<<left<<ch->humalum.energia<<" "<<"Raza: "<<setw(7)<<left<<ch->humalum.especie<<" "<<"Planeta: "<<setw(5)<<left<<ch->humalum.ambiente<<" "<<endl;
            cout<<"SM(0): ["<<setw(5)<<left<<ch->humalum.mochila[0].nacceso<<"] "<<"SM(1): ["<<setw(5)<<left<<ch->humalum.mochila[1].nacceso<<"] "<<"SM(2): ["<<setw(5)<<left<<ch->humalum.mochila[2].nacceso<<"] "<<"SM(3): ["<<setw(5)<<left<<ch->humalum.mochila[3].nacceso<<"] "<<"SM(4): ["<<setw(5)<<right<<ch->humalum.mochila[4].nacceso<<"]"<<endl;
            ch=ch->prxh;}}


void selec_hum(){
    int humcs=0;
    string humc;
    while(humcs!=1){
            cout<<"¡HUMANOS!"<<endl;
            cout<<"¡Seleccionen a su combatiente!"<<endl;
            eq_hum();
            cout<<"Tip: Escribe su nombre tal cual como está registrado"<<endl;
            cin>>humc;
            if((busc_hum(humc))==1){
                cout<<"Los humanos han escogido a: "<<ah->humalum.alumno<<endl;
                humcs=1;}
            else{
                cout<<"¡Por favor, escriban correctamente el nombre de su combatiente!"<<endl;
                cout<<"(O a lo mejor por la falta de oxígeno, están alucinando con uno que no existe)"<<endl;
                cout<<"¡La Guerra intergaláctica está por comenzar, dénse prisa!"<<endl;}}        

}

void ins_andr(string alumno, string especie, int salud, int energia, string ambiente, acceso mochila[]){ //Procedimiento para Insertar alumnos de fidelidad andromedana.
    if(ad==NULL){
        ad=new andros;
        ad->andralum.alumno=alumno;
        ad->andralum.especie=especie;
        ad->andralum.salud=salud;
        ad->andralum.energia=energia;
        ad->andralum.ambiente=ambiente;
        ad->andralum.mochila[0].nacceso=mochila[0].nacceso;
        ad->andralum.mochila[0].salper=mochila[0].salper;
        ad->andralum.mochila[0].energas=mochila[0].energas;
        ad->andralum.mochila[0].impred=mochila[0].impred;
        ad->andralum.mochila[0].salrest=mochila[0].salrest;
        ad->andralum.mochila[0].enerest=mochila[0].enerest;
        ad->andralum.mochila[0].enerest=mochila[0].oxigeno;
        ad->andralum.mochila[1].nacceso=mochila[1].nacceso;
        ad->andralum.mochila[1].salper=mochila[1].salper;
        ad->andralum.mochila[1].energas=mochila[1].energas;
        ad->andralum.mochila[1].impred=mochila[1].impred;
        ad->andralum.mochila[1].salrest=mochila[1].salrest;
        ad->andralum.mochila[1].enerest=mochila[1].enerest;
        ad->andralum.mochila[1].enerest=mochila[1].oxigeno;
        ad->andralum.mochila[2].nacceso=mochila[2].nacceso;
        ad->andralum.mochila[2].salper=mochila[2].salper;
        ad->andralum.mochila[2].energas=mochila[2].energas;
        ad->andralum.mochila[2].impred=mochila[2].impred;
        ad->andralum.mochila[2].salrest=mochila[2].salrest;
        ad->andralum.mochila[2].enerest=mochila[2].enerest;
        ad->andralum.mochila[2].enerest=mochila[2].oxigeno;
        ad->andralum.mochila[3].nacceso=mochila[3].nacceso;
        ad->andralum.mochila[3].salper=mochila[3].salper;
        ad->andralum.mochila[3].energas=mochila[3].energas;
        ad->andralum.mochila[3].impred=mochila[3].impred;
        ad->andralum.mochila[3].salrest=mochila[3].salrest;
        ad->andralum.mochila[3].enerest=mochila[3].enerest;
        ad->andralum.mochila[3].enerest=mochila[3].oxigeno;
        ad->andralum.mochila[4].nacceso=mochila[4].nacceso;
        ad->andralum.mochila[4].salper=mochila[4].salper;
        ad->andralum.mochila[4].energas=mochila[4].energas;
        ad->andralum.mochila[4].impred=mochila[4].impred;
        ad->andralum.mochila[4].salrest=mochila[4].salrest;
        ad->andralum.mochila[4].enerest=mochila[4].enerest;
        ad->andralum.mochila[4].enerest=mochila[4].oxigeno;
        ad->topesalud=salud;
        ad->topenergia=energia;
        bd=ad;
        ed=ad;}
    else{
        ad=new andros;
        ad->andralum.alumno=alumno;
        ad->andralum.especie=especie;
        ad->andralum.salud=salud;
        ad->andralum.energia=energia;
        ad->andralum.ambiente=ambiente;
        ad->andralum.mochila[0].nacceso=mochila[0].nacceso;
        ad->andralum.mochila[0].salper=mochila[0].salper;
        ad->andralum.mochila[0].energas=mochila[0].energas;
        ad->andralum.mochila[0].impred=mochila[0].impred;
        ad->andralum.mochila[0].salrest=mochila[0].salrest;
        ad->andralum.mochila[0].enerest=mochila[0].enerest;
        ad->andralum.mochila[0].enerest=mochila[0].oxigeno;
        ad->andralum.mochila[1].nacceso=mochila[1].nacceso;
        ad->andralum.mochila[1].salper=mochila[1].salper;
        ad->andralum.mochila[1].energas=mochila[1].energas;
        ad->andralum.mochila[1].impred=mochila[1].impred;
        ad->andralum.mochila[1].salrest=mochila[1].salrest;
        ad->andralum.mochila[1].enerest=mochila[1].enerest;
        ad->andralum.mochila[1].enerest=mochila[1].oxigeno;
        ad->andralum.mochila[2].nacceso=mochila[2].nacceso;
        ad->andralum.mochila[2].salper=mochila[2].salper;
        ad->andralum.mochila[2].energas=mochila[2].energas;
        ad->andralum.mochila[2].impred=mochila[2].impred;
        ad->andralum.mochila[2].salrest=mochila[2].salrest;
        ad->andralum.mochila[2].enerest=mochila[2].enerest;
        ad->andralum.mochila[2].enerest=mochila[2].oxigeno;
        ad->andralum.mochila[3].nacceso=mochila[3].nacceso;
        ad->andralum.mochila[3].salper=mochila[3].salper;
        ad->andralum.mochila[3].energas=mochila[3].energas;
        ad->andralum.mochila[3].impred=mochila[3].impred;
        ad->andralum.mochila[3].salrest=mochila[3].salrest;
        ad->andralum.mochila[3].enerest=mochila[3].enerest;
        ad->andralum.mochila[3].enerest=mochila[3].oxigeno;
        ad->andralum.mochila[4].nacceso=mochila[4].nacceso;
        ad->andralum.mochila[4].salper=mochila[4].salper;
        ad->andralum.mochila[4].energas=mochila[4].energas;
        ad->andralum.mochila[4].impred=mochila[4].impred;
        ad->andralum.mochila[4].salrest=mochila[4].salrest;
        ad->andralum.mochila[4].enerest=mochila[4].enerest;
        ad->andralum.mochila[4].enerest=mochila[4].oxigeno;
        ad->topesalud=salud;
        ad->topenergia=energia;
        ed->prxd=ad;
        ed=ed->prxd;}
    ed->prxd=NULL;
}

int busc_andr(string alumno){ 
    ad=bd;
    while(ad!=NULL){
        if(ad->andralum.alumno!=alumno){
            ad=ad->prxd;}
        else{
            return 1;}
    }
    return 0;
}

void mort_andr(string alumno){
    struct andros *zd=NULL,*xd=NULL; 
    zd=bd;
    while(zd!=NULL && zd->andralum.alumno!=alumno){
        xd=zd;
        zd=zd->prxd;}
        if(zd==bd){
            bd=bd->prxd;}
        else{
            xd->prxd=zd->prxd;
            delete(zd);}
}

void eq_andr(){
    struct andros *cd=NULL;
    cout<<".-.-.-.-.-.-.-.-.-.-.-.-.ESTADÍSTICAS DE ANDROMEDANOS (CONSULTA DE EQUIPO).-.-.-.-.-.-.-.-.-.-.-."<<endl;
        cd=bd;
        while(cd!=NULL){
            cout<<setw(11)<<left<<cd->andralum.alumno<<"   "<<"HP: "<<setw(5)<<left<<cd->andralum.salud<<" "<<"SP: "<<setw(7)<<left<<cd->andralum.energia<<" "<<"Raza: "<<setw(7)<<left<<cd->andralum.especie<<" "<<"Planeta: "<<setw(5)<<left<<cd->andralum.ambiente<<" "<<endl;
            cout<<"SM(0): ["<<setw(5)<<left<<cd->andralum.mochila[0].nacceso<<"] "<<"SM(1): ["<<setw(5)<<left<<cd->andralum.mochila[1].nacceso<<"] "<<"SM(2): ["<<setw(5)<<left<<cd->andralum.mochila[2].nacceso<<"] "<<"SM(3): ["<<setw(5)<<left<<cd->andralum.mochila[3].nacceso<<"] "<<"SM(4): ["<<setw(5)<<right<<cd->andralum.mochila[4].nacceso<<"]"<<endl;
            cd=cd->prxd;}
}    

void selec_andr(){
    int andrcs=0;
    string andrc;
    while(andrcs!=1){
            cout<<"¡ANDROMEDANOS!"<<endl;
            cout<<"¡Seleccionen a su combatiente!"<<endl;
            eq_andr();
            cout<<"Tip: Escribe su nombre tal cual como está registrado"<<endl;
            cin>>andrc;
            if((busc_andr(andrc))==1){
                cout<<"Los Andromedanos han escogido a: "<<ad->andralum.alumno<<endl;
                andrcs=1;}
            else{
                cout<<"¡Por favor, escriban correctamente el nombre de su combatiente!"<<endl;
                cout<<"(O a lo mejor por la falta de oxígeno, están alucinando con uno que no existe)"<<endl;
                cout<<"¡La Guerra intergaláctica está por comenzar, dénse prisa!"<<endl;}}        

}

void fin_guerra(){
    if(ah==NULL){
        cout<<"|||.-.-.-.-.-.-.-.-.-.-.-.-.-REPORTE INTERSTELAR DE ÚLTIMA HORA.-.-.-.-..-.-.-.-..-.-.-.|||"<<endl;
        sleep(1);
        cout<<"|||.-.-.-.-.-.-.-.-..-.-.-.-¡LA HUMANIDAD HA CAÍDO DE RODILLAS!-.-.-.-.-.-.-.--..-.-.-.-|||"<<endl;
        sleep(1);
        cout<<"|||.-.-.-.-.-.-.-.-.-.-¡ANDROMEDANOS SE PROCLAMAN DUEÑOS DE LA GALAXIA!.-.-.-.-.-.-.-.-.|||"<<endl;
        sleep(1);
        cout<<"|||Después de un que el último alumno del bando de los humanos, fuera atravesado por el |||"<<endl;
        cout<<"||magma de un Piromartillo, se conquistó el cuadrante C0304, otorgando a los andromedanos||"<<endl;
        cout<<"|| un punto estratégico del que se desplegaron FutumeTronaveS, extinguiendo al resto de  ||"<<endl;
        cout<<"|| razas alienígenas, creando planetas inhóspitos y destruyendo sistemas solares a gran  ||"<<endl;
        cout<<"|||estableciendo una tiranía intergaláctica de dolor y sufrimiento hasta el año +∞56e91.|||"<<endl;
        sleep(10);
        cout<<endl;
        cout<<endl;
        menu_principal();}
        if(ad==NULL){
            cout<<"|||.-.-.-.-.-.-.-.-.-.-.-.-.-REPORTE INTERSTELAR DE ÚLTIMA HORA.-.-.-.-..-.-.-.-..-.-.-.|||"<<endl;
            sleep(1);
            cout<<"|||.-.-.-.-.-.-.-.-.-.-.¡ANDROMEDANOS SUCCIONADOS POR UN AGUJERO NEGRO!-.-.-.-.-.-.-.-.-|||"<<endl;
            sleep(1);
            cout<<"|||.-.-.-.-.-.-.-.-.-.¡CONCLUYE LA GUERRA INTERGALÁCTICA EN EL AÑO 3101!.-.-.-.-.-.-.-.-|||"<<endl;
            sleep(1);
            cout<<"|||La Balazul de un Cerónivas se teledirigió e impactó en los motores de la nave Nodriza|||"<<endl;
            cout<<"||Andromedana, desviándola a un agujero negro IC 432 Primordial. Brindando gran ventaja a||"<<endl;
            cout<<"||los humanos para ganar la guerra, desmantelando el resto de bases, erradicando a RBlion||"<<endl;
            cout<<"||ANDR78, y haciendo recapacitar a los sobrevivientes, instaurando la paz universal. Pero||"<<endl;
            cout<<"|||no duraría mucho ya que una mortífera plaga, consumiría toda forma de vida existente. |||"<<endl;
            sleep(10);
            cout<<endl;
            cout<<endl;
            menu_principal();}
}


void turn_hum(){
    int acch=0; //Accesorio escogido Humano
    int wacch=0; //Variable para comprobar que el accesorio escogido es correcto
    int tps=0, tpe=0; //topesalud, topevariable COPIAS
    int shpsr=0, ssper=0; //suma vida+vida restaurada, suma energía+energía restaurada
    int hpq=0, spq=0; //exceso de vida restaurada, exceso de energía restaurada
    int hpr=0, spr=0; //nuevo monto de vida, nuevo monto de energía
    string humrem; //variable para el reemplazo de alumno, en caso de que fallezca
    int whumrem=0; //variable para controlar el while del reemplazo del alumno
    int cmhum=0; //contador de muertes humanas
    random_device distms;
    uniform_int_distribution<int> distmsj(1,3);
    int msj;
    if(ah->humalum.salud<=0 || ah->humalum.energia<=0){
        ad->andralum.energia=ad->andralum.energia+ah->humalum.energia; //Mecánica de Energía pendiente 15%
        cout<<"¡"<<ah->humalum.alumno<<" ha caído en batalla!"<<endl;
        mort_hum(ah->humalum.alumno);
        cout<<"¡Hemos perdido un combatiente!"<<endl;
        while(whumrem<1){
            cmhum=cmhum+1;
            if(cmhum==3){
                cout<<"¡Hemos perdido la guerra!"<<endl;
                fin_guerra();}
            eq_hum();
            cout<<"Escoge tu próximo alumno:"<<endl;
            cout<<"Tip: Recuerda escribir el nombre como está registrado"<<endl;
            cin>>humrem;
            if(busc_hum(humrem)==1){
                msj=distmsj(distms);
                if(msj==1){
                    cout<<"¡De prisa "<<ah->humalum.alumno<<"!"<<endl;
                    whumrem=1;}
                if(msj==2){
                    cout<<"¡Confíamos en ti "<<ah->humalum.alumno<<"!"<<endl;
                    whumrem=1;}
                if(msj==3){
                    cout<<"¡ "<<ah->humalum.alumno<<" haz lo tuyo!"<<endl;
                    whumrem=1;}}
            else{
                cout<<"¡Por favor, escriban correctamente el nombre de su combatiente!"<<endl;
                cout<<"(O a lo mejor por la falta de oxígeno, están alucinando con uno que no existe)"<<endl;
                cout<<"¡Acabamos de perder un soldado, dénse prisa!"<<endl;}}}

    //////////////////////////////////////////////////////////////////////////////////////////////////////           

    cout<<".-.-.-.-.-.-.-.-.-.-.-.-.HUMANO EN CAMPO DE BATALLA (CONSULTA DE ACCIONES).-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cout<<ah->humalum.alumno<<"   "<<"HP: "<<setw(5)<<left<<ah->humalum.salud<<" "<<"SP: "<<setw(7)<<left<<ah->humalum.energia<<" "<<"Raza: "<<setw(7)<<left<<ah->humalum.especie<<" "<<"Planeta: "<<setw(5)<<left<<ah->humalum.ambiente<<" "<<endl;
    cout<<"SM(0): ["<<setw(5)<<left<<ah->humalum.mochila[0].nacceso<<"] "<<"SM(1): ["<<setw(5)<<left<<ah->humalum.mochila[1].nacceso<<"] "<<"SM(2): ["<<setw(5)<<left<<ah->humalum.mochila[2].nacceso<<"] "<<"SM(3): ["<<setw(5)<<left<<ah->humalum.mochila[3].nacceso<<"] "<<"SM(4): ["<<setw(5)<<right<<ah->humalum.mochila[4].nacceso<<"]"<<endl;
    while(wacch<1){
        cout<<"¿Qué slot de su mochila utilizará "<<ah->humalum.alumno<<" ?"<<endl;
        cin>>acch;
        if(acch>=0 && acch<=4){
            cout<<ah->humalum.alumno<<" usará: "<<ah->humalum.mochila[acch].nacceso<<endl;
            if(ad->barrera==0){
                ad->andralum.salud=ad->andralum.salud-ah->humalum.mochila[acch].salper;}      //Si es Acc de Ataque le resta hp al rival
            else{
                ad->andralum.salud=ad->andralum.salud-(ah->humalum.mochila[acch].salper-ad->barrera);}
            ah->humalum.energia=ah->humalum.energia-ah->humalum.mochila[acch].energas; //Si es Acc de Ataque le resta sp al usuario
            ah->barrera=ah->humalum.mochila[acch].impred;                                //Si es Acc de Defensa para establecer la barrera
            if(ah->humalum.salud+ah->humalum.mochila[acch].salrest>ah->topesalud){      //Si es Acc de R. de Salud
                tps=ah->topesalud;//Variable tps para guardar el tope de salud del alumno, sin perder el original, ej:100
                shpsr=ah->humalum.salud+ah->humalum.mochila[acch].salrest; //ej: 80+25
                hpq=shpsr-tps; //ej: 5=80+25-100
                hpr=shpsr-hpq; //ej: 25+80-5
                ah->humalum.salud=hpr;}
            if(ah->humalum.salud+ah->humalum.mochila[acch].salrest<ah->topesalud){
                shpsr=ah->humalum.salud+ah->humalum.mochila[acch].salrest; //ej: 30+10, siendo el tope de energia 60
                hpr=shpsr; //ej: 40=30+10
                ah->humalum.salud=hpr;}
            //Mismo procedimiento con la Energía        
            if(ah->humalum.energia+ah->humalum.mochila[acch].enerest>ah->topenergia){  //Si es Acc de R. de Energía
                tpe=ah->topenergia;//Variable tps para guardar el tope de salud del alumno, sin perder el original, ej:100
                ssper=ah->humalum.energia+ah->humalum.mochila[acch].enerest; //ej: 80+25
                spq=ssper-tpe; //ej: 5=80+25-100
                spr=ssper-spq; //ej: 25+80-5
                ah->humalum.energia=spr;}
            if(ah->humalum.energia+ah->humalum.mochila[acch].enerest<ah->topenergia){
                ssper=ah->humalum.energia+ah->humalum.mochila[acch].enerest; //ej: 30+10, siendo el tope de energia 60
                spr=ssper; //ej: 40=30+10
                ah->humalum.energia=spr;}
            /*if(ad->andralum.mochila[accd].oxigeno==ap->oxigeno || ad->andralum.ambiente==ap->ambiente){
                cout<<"estoy pensando"<<endl;}*/
            if(ah->humalum.mochila[acch].oxigeno!=ap->oxigeno && ah->humalum.ambiente!=ap->ambiente){
                cout<<"¡Debido a la atmósfera "<<ah->humalum.alumno<<" está padeciendo!"<<endl;
                cout<<"¡"<<ah->humalum.alumno<<" pierde un tercio de salud!"<<endl;
                ad->andralum.salud=ad->andralum.salud-(ad->andralum.salud/3);}
            wacch=1;}        
        else{
            cout<<"¡Ese slot de la mochila no existe!"<<endl;
            cout<<"Recuerda que una mochila tiene de 0-4 slots"<<endl;}}
}

void turn_andr(){
    int accd=0; //Accesorio escogido Andromedano
    int waccd=0; //Variable para comprobar que el accesorio escogido es correcto
    int tps=0, tpe=0; //topesalud, topevariable COPIAS
    int shpsr=0, ssper=0; //suma vida+vida restaurada, suma energía+energía restaurada
    int hpq=0, spq=0; //exceso de vida restaurada, exceso de energía restaurada
    int hpr=0, spr=0; //nuevo monto de vida, nuevo monto de energía
    string andrrem; //variable para el reemplazo de alumno, en caso de que fallezca
    int wandrrem=0; //variable para controlar el while del reemplazo del alumno
    int cmandr=0; //contador de muertes andromedanas
    random_device distms;
    uniform_int_distribution<int> distmsj(1,3);
    int msj;
    if(ad->andralum.salud<=0 || ad->andralum.energia<=0){
        ah->humalum.energia=ah->humalum.energia+ad->andralum.energia; //Mecánica de Energía pendiente 15%
        cout<<"¡"<<ad->andralum.alumno<<" sucumbió ante sus heridas!"<<endl;
        mort_andr(ad->andralum.alumno);
        cout<<"¡Hemos perdido un combatiente!"<<endl;
        while(wandrrem<1){
            cmandr=cmandr+1;
            if(cmandr==3){
                cout<<"¡Hemos perdido la guerra!"<<endl;
                fin_guerra();}
            eq_andr();
            cout<<"Escoge tu próximo alumno:"<<endl;
            cout<<"Tip: Recuerda escribir el nombre como está registrado"<<endl;
            cin>>andrrem;
            if(busc_andr(andrrem)==1){
                msj=distmsj(distms);
                if(msj==1){
                    cout<<"¡Vamos "<<ad->andralum.alumno<<"!"<<endl;
                    wandrrem=1;}
                if(msj==2){
                    cout<<"¡Demuestra lo que vales "<<ad->andralum.alumno<<"!"<<endl;
                    wandrrem=1;}
                if(msj==3){
                    cout<<"¡ "<<ad->andralum.alumno<<" dales su merecido a esos traidores!"<<endl;
                    wandrrem=1;}}
            else{
                cout<<"¡Por favor, escriban correctamente el nombre de su combatiente!"<<endl;
                cout<<"(O a lo mejor por la falta de oxígeno, están alucinando con uno que no existe)"<<endl;
                cout<<"¡Acabamos de perder un soldado, dénse prisa!"<<endl;}}}
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<".-.-.-.-.-.-.-.-.-.-.-.-.ANDROMEDANO EN CAMPO DE BATALLA (CONSULTA DE ACCIONES).-.-.-.-.-.-.-.-.-.-.-."<<endl;
    cout<<ad->andralum.alumno<<"   "<<"HP: "<<setw(5)<<left<<ad->andralum.salud<<" "<<"SP: "<<setw(7)<<left<<ad->andralum.energia<<" "<<"Raza: "<<setw(7)<<left<<ad->andralum.especie<<" "<<"Planeta: "<<setw(5)<<left<<ad->andralum.ambiente<<" "<<endl;
    cout<<"SM(0): ["<<setw(5)<<left<<ad->andralum.mochila[0].nacceso<<"] "<<"SM(1): ["<<setw(5)<<left<<ad->andralum.mochila[1].nacceso<<"] "<<"SM(2): ["<<setw(5)<<left<<ad->andralum.mochila[2].nacceso<<"] "<<"SM(3): ["<<setw(5)<<left<<ad->andralum.mochila[3].nacceso<<"] "<<"SM(4): ["<<setw(5)<<right<<ad->andralum.mochila[4].nacceso<<"]"<<endl;
    while(waccd<1){
        cout<<"¿Qué slot de su mochila utilizará "<<ad->andralum.alumno<<" ?"<<endl;
        cin>>accd;
        if(accd>=0 && accd<=4){
            cout<<ad->andralum.alumno<<" usará: "<<ad->andralum.mochila[accd].nacceso<<endl;
            if(ah->barrera==0){
                ah->humalum.salud=ah->humalum.salud-ad->andralum.mochila[accd].salper;}      //Si es Acc de Ataque le resta hp al rival
            else{
                ah->humalum.salud=ah->humalum.salud-(ad->andralum.mochila[accd].salper-ah->barrera);}
            ad->andralum.energia=ad->andralum.energia-ad->andralum.mochila[accd].energas; //Si es Acc de Ataque le resta sp al usuario
            ad->barrera=ad->andralum.mochila[accd].impred;                                //Si es Acc de Defensa para establecer la barrera
            if(ad->andralum.salud+ad->andralum.mochila[accd].salrest>ad->topesalud){      //Si es Acc de R. de Salud
                tps=ad->topesalud;//Variable tps para guardar el tope de salud del alumno, sin perder el original, ej:100
                shpsr=ad->andralum.salud+ad->andralum.mochila[accd].salrest; //ej: 80+25
                hpq=shpsr-tps; //ej: 5=80+25-100
                hpr=shpsr-hpq; //ej: 25+80-5
                ad->andralum.salud=hpr;}
            if(ad->andralum.salud+ad->andralum.mochila[accd].salrest<ad->topesalud){
                shpsr=ad->andralum.salud+ad->andralum.mochila[accd].salrest; //ej: 30+10, siendo el tope de energia 60
                hpr=shpsr; //ej: 40=30+10
                ad->andralum.salud=hpr;}
            //Mismo procedimiento con la Energía        
            if(ad->andralum.energia+ad->andralum.mochila[accd].enerest>ad->topenergia){  //Si es Acc de R. de Energía
                tpe=ad->topenergia;//Variable tps para guardar el tope de salud del alumno, sin perder el original, ej:100
                ssper=ad->andralum.energia+ad->andralum.mochila[accd].enerest; //ej: 80+25
                spq=ssper-tpe; //ej: 5=80+25-100
                spr=ssper-spq; //ej: 25+80-5
                ad->andralum.energia=spr;}
            if(ad->andralum.energia+ad->andralum.mochila[accd].enerest<ad->topenergia){
                ssper=ad->andralum.energia+ad->andralum.mochila[accd].enerest; //ej: 30+10, siendo el tope de energia 60
                spr=ssper; //ej: 40=30+10
                ad->andralum.energia=spr;}
            /*if(ad->andralum.mochila[accd].oxigeno==ap->oxigeno || ad->andralum.ambiente==ap->ambiente){
                cout<<"estoy pensando"<<endl;}*/
            if(ad->andralum.mochila[accd].oxigeno!=ap->oxigeno && ad->andralum.ambiente!=ap->ambiente){
                cout<<"¡El oxígeno de este planeta es muy ínfimo para "<<ah->humalum.alumno<<"!"<<endl;
                cout<<"¡"<<ah->humalum.alumno<<" pierde un tercio de salud!"<<endl;
                ad->andralum.salud=ad->andralum.salud-(ad->andralum.salud/3);}
            waccd=1;}        
        else{
            cout<<"¡Ese slot de la mochila no existe!"<<endl;
            cout<<"Recuerda que una mochila tiene de 0-4 slots"<<endl;}}
}

int busc_amb_oxi(int ox){ 
    ap=bp;
    while(ap!=NULL){
        if(ap->oxigeno!=ox){
            ap=ap->prxpl;}
        else{
            return 1;}
    }
    return 0;
}

void combate(){
    random_device ramb, ramf, ramp; //random de ambiente, random de fidelidad
    int rambe,ramfe, rampck; //random amb escogido, random de fid escogido, random de primer ataque escogido
    int rambec=0;
    int ramfc=0, ramfch=0, ramfcd=0;
    string ambesc; //ambiente escogido
    int oxambesc; //oxigeno escogido
    int hum=0,andr=0;
    int alres=0;
    struct solds *sf;
    string humc, andrc; //humano combatiente seleccionado, andromedano combatiente seleccionado
    int humcs, adrcs; //Para el While de selección
    uniform_int_distribution<int> distamb(90,100);
    uniform_int_distribution<int> distfid(1,2);
    uniform_int_distribution<int> distpck(1,2);

    if(sc==1){
        if(sc<6){
            alres=6-sc;
            cout<<"¡¡UUUPPPSSS!!"<<endl;
            cout<<"¡El número de alumnos es inferior al requerido, para luchar!"<<endl;
            cout<<"(Registra únicamente ["<<alres<<"] alumnos)"<<endl;}
        if(sc>6){
            cout<<"¡¡UUUPPPSSS!!"<<endl;
            cout<<"¡El número de alumnos es superior al requerido, para luchar!"<<endl;
            cout<<"(¡Elimina los necesarios para salvar esta compañía! (Referencia Pixar))"<<endl;}}
    else{
        sf=bs;
        cout<<".-.-.-.-.-FIEL [Ó] METRO..-.-.-..-.-.-"<<endl;
        cout<<"Inspeccionando Fidelidad de Alumnos..."<<endl;
        while(ramfc<6 && sf!=NULL){
            ramfe=distfid(ramf);                                  
            if(ramfe==1 && ramfch!=3){    
                ins_hum(sf->alumno,sf->especie,sf->salud,sf->energia,sf->ambiente,sf->mochila);//hsf
                ramfch=ramfch+1;
                ramfc=ramfc+1;
                sf=sf->prxsol;}

            if(ramfe==2 && ramfcd!=3){
                ins_andr(sf->alumno,sf->especie,sf->salud,sf->energia,sf->ambiente,sf->mochila);
                ramfcd=ramfcd+1;
                ramfc=ramfc+1;
                sf=sf->prxsol;}}
        cout<<"Interrogando Sospechosos.-.-.-.-.-.-.-"<<endl;
        sleep(1);
        cout<<"Analizando Expedientes.-.-.-.-.-.-.-.-"<<endl;
        sleep(1);
        cout<<"¡Se ha descubierto la fidelidad de los alumnos!"<<endl;
        cout<<endl;
        cout<<endl;
        eq_hum();
        cout<<endl;
        cout<<endl;
        eq_andr();
        sleep(10);
        cout<<".-.-.-.-.-SELECTOR [D] PLANETAS.-.-.-."<<endl;
        cout<<"Escogiendo ambiente de combate.-.-.-.-"<<endl;
        while(rambec!=3){
            rambe=distamb(ramb);
            if(busc_amb_oxi(rambe)==1){
                cout<<"-.-.-.-.-"<<ap->ambiente<<"-.-.-.-.-"<<endl;
                rambec=rambec+1;
                sleep(1);
                if(rambec>=2){
                    while(rambec!=3){
                    rambe=distamb(ramb);
                    if(busc_amb_oxi(rambe)==1){
                        cout<<"El ambiente escogido fue:"<<endl;
                        cout<<"-.-.-.-.-¡"<<ap->ambiente<<"!-.-.-.-.-"<<endl;
                        oxambesc=ap->oxigeno;
                        ambesc=ap->ambiente;
                        rambec=rambec+1;}
                    else{
                        rambe=distamb(ramb);}}}          
            else{
                rambe=distamb(ramb);}}}
        cout<<"¡Que empiece el combate intergaláctico!"<<endl;
        cout<<endl;
        cout<<endl;
        selec_hum();
        cout<<endl;
        cout<<endl;
        selec_andr();
        rampck=distpck(ramp); 
        if(rampck==1){
            cout<<"¡ALGUIEN TIENE UNA VENTAJA!"<<endl;
            cout<<"¡Los Humanos atacan primero!"<<endl;
            while(ah!=NULL || ad!=NULL){
                turn_hum();
                cout<<endl;
                cout<<endl;
                turn_andr();}}
        if(rampck==2){
            cout<<"¡ALGUIEN TIENE UNA VENTAJA!"<<endl;
            cout<<"¡Los Andromedanos atacan primero!"<<endl;
            while(bh!=NULL || bd!=NULL){
                turn_andr();
                cout<<endl;
                cout<<endl;
                turn_hum();}}}
}

void nom_estad(){
    cout<<".-.NOMENCLATURA DE ESTADÍSTICAS.-."<<endl;
    cout<<".-.-.-.-.-.(NUMÉRICAS)-.-..-.-.-.-"<<endl;
    cout<<"-.-.Salud:              'HP'.-.-.-"<<endl;
    cout<<"-.-.Energía:            'SP'.-.-.-"<<endl;
    cout<<"-.-.Nivel de Oxígeno:   'NOX'-.-.-"<<endl;
    cout<<"-.-.Slot de Mochila:    'SM()'-.-."<<endl;
    cout<<"-.-.Daño Infligido:     'DI'.-.-.-"<<endl;
    cout<<"-.-.Energía Gastada:    'EG'-.-.-."<<endl;
    cout<<"-.-.Salud Restaurada:   'SR'.-.-.-"<<endl;
    cout<<"-.-.Energía Restaurada: 'ER'.-.-.-"<<endl;
}

int main() {
    //Variables Alien
    string amb, esp;
    int hp,sp;

    //Variables Accesorios
    string nac;
    int hpp,spg,dr,hpr,spr,ox;

    //Variables Soldados
    string aluma,alumn;
    int cs,is,i,sc;
    //Reutiliza esp, amb, hp y sp de las variables de los Alien
    
    //Variables Ambiente
    //Reutiliza ox de los Accesorios y amb de los Alien

    //Variables del Menú (y submenúes)
    int mp, submal, submacr, submac, submsol, submap;
    //Aliens
    int wal1=0,wal2=0;
    //Ambiente
    int wame=0, wamb1=0, wamb2=0;

    default_amb();
    default_alien();
    default_acceso();

    bool cerrar=false;
    while(!cerrar){
        mp=menu_principal();
        switch(mp){
            // Gestión de Especies
            case 1:
                while(true){
                    submal=submenu_aliens();
                    if(submal==5)break;
                    switch(submal){
                        case 1:
                            wal1=0;
                            wal2=0;
                            crea_alien();
                            break;
                        case 2:
                            cout<<"Selecciona la especie que deseas modificar:"<<endl;
                            cout<<"Tip: Escribe el nombre EXACTAMENTE como aparece en la lista"<<endl;
                            mos_alien();
                            cin>>esp;
                            mod_alien(esp);
                            break;
                        case 3:
                            cout<<"Selecciona la especie que deseas eliminar:"<<endl;
                            cout<<"Tip: Escribe el nombre EXACTAMENTE como aparece en la lista"<<endl;
                            mos_alien();
                            cin>>esp;
                            elim_alien(esp);
                            break;
                        case 4:
                            mos_alien();
                            break;
                        default:
                            cout<<".-.-.|OPCIÓN INVÁLIDA...|.-.-."<<endl;    
                    }
                }
                break;
             // Gestión de Accesorios    
            case 2:
                while(true){
                    submac=submenu_acceso();
                    if(submac==5)break;
                    switch(submac){
                        case 1:
                            crea_acceso();
                            break;
                        case 2:
                            cout<<"Escribe el nombre del accesorio que deseas modificar:"<<endl;
                            cout<<"Tip: Recuerda escribir todo en MAYÚSCULAS"<<endl;
                            mos_acceso();
                            cin>>nac;
                            mod_acceso(nac);
                            break;
                        case 3:
                            cout<<"Escribe el nombre del accesorio que deseas eliminar"<<endl;
                            cout<<"Tip: Recuerda escribir todo en MAYÚSCULAS"<<endl;
                            cin>>nac;
                            elim_acceso(nac);
                            break;
                        case 4:
                            mos_acceso();
                            break;
                        default:
                            cout<<".-.-.|OPCIÓN INVÁLIDA...|.-.-."<<endl;    
                    }
                }
                break;
             // Gestión de Soldados y Mochilas    
            case 3:
                while(true){
                    submsol=submenu_solds();
                    if(submsol == 7)break;
                    switch(submsol){
                        case 1:
                            agg_solds();
                            break;
                        case 2:
                            mos_solds();
                            cout<<"Ingresa el nombre del soldado que deseas modificar:"<<endl;
                            cout<<"Tip: Recuerda escribirlo correctamente"<<endl;
                            cin>>alumn;
                            mod_solds(alumn);
                            break;
                        case 3:
                            mos_solds();
                            cout<<"Ingresa el nombre del soldado que deseas eliminar:"<<endl;
                            cout<<"Tip: Recuerda escribirlo correctamente"<<endl;
                            cin>>alumn;
                            elim_solds(alumn);
                            break;
                        case 4:
                            mos_solds();
                            cout<<"Ingresa el nombre del soldado para llenar su mochila:"<<endl;
                            cout<<"Tip: Recuerda escribirlo correctamente"<<endl;
                            cin>>alumn;
                            agg_mochila(alumn);
                            break;
                        case 5:
                            mos_solds();
                            cout<<"Ingresa el nombre del soldado para modificar el contenido de su mochila:"<<endl;
                            cout<<"Tip: Recuerda escribirlo correctamente"<<endl;
                            cin>>alumn;
                            mod_mochila(alumn);
                            break;
                        case 6:
                            mos_solds();
                            cout<<"Ingresa el nombre del soldado para eliminar el contenido de su mochila:"<<endl;
                            cout<<"Tip: Recuerda escribirlo correctamente"<<endl;
                            cin>>alumn;
                            elim_mochila(alumn);
                            break;
                        default:
                            cout<<".-.-.|OPCIÓN INVÁLIDA...|.-.-."<<endl;    
                    }
                }
                break;
            // Gestión de Ambientes    
            case 4:
                while(true){
                    submap=submenu_amb();
                    if(submap==5)break;
                    switch(submap){
                        case 1:
                            crea_amb();
                            break;
                        case 2:
                            mod_amb();
                            break;
                        case 3:
                            cout<<"Ingresa el nombre del ambiente que deseas eliminar:"<<endl;
                            cout<<"Tip: Recuerda escribirlo en MAYÚSCULAS"<<endl;
                            mos_amb();
                            cin>>amb;
                            elim_amb(amb);
                            break;
                        case 4:
                            mos_amb();
                            break;
                        default:
                            cout<<".-.-.|OPCIÓN INVÁLIDA...|.-.-."<<endl;    

                    }
                }
                break;
            case 5:
                cons_eq();
                break;
            case 6:
                combate();
                break;    
            case 7:
                nom_estad();
                break;    
            case 8:
                cerrar=true;
                break;
            default:
                cout<<".-.-.|OPCIÓN INVÁLIDA...|.-.-."<<endl;
                break;
        }
    }

    return 0;
}