#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void spasi(int berapa) {
    for (int i = 0; i < berapa; i++) {
        cout << endl;
    }
};

struct enemy {
    string nama;
    int hp;
    int enemy_damage;
};struct enemy musuh;

int hitungDamageDiTerimaMusuh (int damage) {
    string blank1;
    musuh.hp -= damage;
    if (musuh.hp < 0) {
            musuh.hp = 0;
    } getline(cin, blank1);
    system("cls");
    cout << "=====================================" << endl;
    cout << "Hp " << "[" + musuh.nama + "] " << "sekarang: " << musuh.hp << endl;
    cout << "=====================================";
    getline(cin, blank1);
    system("cls");
    return musuh.hp;
};

void header () {
    cout<< "Masukkan informasi tentangmu" <<endl;
};

struct info{
    string first_name;
    string nickname;
    int jobPilih;
    string job;
    int hp = 100;
    int ksatria_bonus = 50;

}; struct info player;

void playerinfo () {
    do {
        cout << "Nama : ";
        getline(cin, player.first_name);
        if (player.first_name.empty()) {
                cout << "Nama tidak boleh kosong. Silakan coba lagi.";
                spasi(2);
            }
        } while (player.first_name.empty());
    do {
        cout << "Nama Panggilan: ";
        getline(cin, player.nickname);
        } while (player.nickname.empty());
    cout << "\n1. Penyihir" << endl;
    cout << "2. Ksatria" << endl;
    cout << "Piih Job/Kelas (1/2) >> ";
    cin >> player.jobPilih;
};

void seranganPlayerPenyihir (int serangan = 0, int attack1=75, int attack2=50) {
    cout << "1. Hollow Purple (75 Damage)" << endl << "2. Normal Attack (50 Damage)" << endl;
    cout << "Pilih serangan (1/2) >> ";
    cin >> serangan;
    if (serangan==1) {
        serangan = attack1;
    } else if (serangan==2){
        serangan = attack2;
    } else {
        cout << "Pilihan tidak valid, menggunakan Normal Attack";
        spasi(2);
        serangan = attack2;
    }
    hitungDamageDiTerimaMusuh(serangan);
};

void seranganPlayerKsatria (int serangan = 0, int attack1=50, int attack2=25) {
    cout << "1. Super Slash (50 Damage)" << endl << "2. Normal Attack (25 Damage)" << endl;
    cout << "Pilih serangan (1/2) >> ";
    cin >> serangan;
    string blank;
    if (serangan==1) {
        serangan = attack1;
    } else if (serangan==2){
        serangan = attack2;
    } else {
        cout << "Pilihan tidak valid, menggunakan Normal Attack"<< endl;
        serangan = attack2;
        getline(cin, blank);
    }
    hitungDamageDiTerimaMusuh(serangan);
};

void infoMusuh() {
    cout << "=====================================" << endl;
    cout << "Nama Monster: " << musuh.nama << endl;
    cout << "Hp: " << musuh.hp << endl;
    cout << "Kekuatan Serangan: " << musuh.enemy_damage << " (Meningkat seiring waktu)" << endl;
    cout << "=====================================";
    spasi(2);
};

void infoPemain() {
    cout << "=====================================" << endl;
    cout << "Nama Pemain: " << player.first_name + " (" + player.nickname + ")" << endl;
    cout << "Hp: " << player.hp << endl;
    cout << "Job/Kelas: " << player.job << endl;
    cout << "=====================================";
    spasi(2);
};

int hpTerbaruPemain() {
    string blank;
    player.hp -= musuh.enemy_damage;
    if (player.hp < 0) {
            player.hp = 0;
    }
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
    cout << "Musuh melakukan serangan!!!" << endl << "(" + player.nickname + ") " << "menerima " <<  musuh.enemy_damage << " damage!" << endl;
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
    spasi(2);
    cout << "=====================================" << endl;
    cout << "Hp " << "(" + player.nickname + ") " << "sekarang: " << player.hp << endl;
    cout << "=====================================";
    spasi(1);
    musuh.enemy_damage += 20;
    getline(cin, blank);

    return player.hp;
};

void end(){
    spasi(2);
    cout << "==============================================================================" << endl;
    cout << "(" + player.nickname + ") " << "pun berbalik dan melanjutkan perjalannya ke desa/kota berikutnya" << endl;
    cout << "==============================================================================" << endl;
    spasi(2);
};

int main()
{
    musuh.nama = "Troll";
    musuh.hp = 100;
    musuh.enemy_damage = 20;

    string blank;
    string confirm;
    string response;
    string quest1[7]={"Hai, kau.. petualang?", "Aku baru melihatmu disekitar sini, kau pasti petualang baru. Bagaimana pendapat mu tentang tempat ini?",
    "Sebenarnya, aku ingin minta tolong", "Bisakah kau membantu ku untuk membunuh monster di goa itu.\n\t\tKu mohon, monster itu telah membuat kami para penduduk desa resah", "Terima Kasih.", "Terima kasih banyak, ", "Baiklah kalau begitu, sampai jumpa"};
    int level;
    do {
        header();
        playerinfo();
        getline(cin, blank);
        cout << "Ada kesalahan? Ingin mengisi ulang?" << endl;
        do {
            cout << "(Ya/Tidak) >> ";
            getline(cin, confirm);
        } while (confirm.empty());
        system("cls");
    } while (confirm == "Ya" || confirm == "YA" || confirm == "ya" || confirm == "y" || confirm == "Y");
    if (player.jobPilih==1) {
        player.job = "Penyihir";
    } else if (player.jobPilih ==2 ) {
        player.job = "Ksatria";
        player.hp += player.ksatria_bonus;
    } else {
        player.jobPilih == 2;
        player.job = "Ksatria";
        player.hp += player.ksatria_bonus;
    }
    cout << "Kau adalah seorang " << "(" + player.job + ")" << " dengan nama panggilan " << "(" + player.nickname + ") " << "yang sedang memasuki sebuah desa"<< endl;
    cout << "(Semua pilihan default akan berakhir positif/pilihan Ya)";
    spasi(2);
    for (int a=0; a<3; a++) {
        cout << "(Penduduk Desa) "<< quest1[a] << endl << "Response>> ";
        getline(cin, response);
        while (response.empty()) {
            cout << "Response>> ";
            getline(cin, response);
        }
        cout << endl;
    }
    cout << "(Penduduk Desa)\t"<< quest1[3] << endl << "Response>> (Ya/Tidak) >> ";
    getline(cin, response);
    while (response.empty()) {
            cout << "Response>> (Ya/Tidak) >> ";
            getline(cin, response);
        }
    if (response == "Tidak" || response == "tidak" || response == "TIDAK") {
        system("cls");
        cout << "(Penduduk Desa) "<< quest1[6] << endl;
        end();
        } else {
            system("cls");
            cout << "(" + player.nickname + ") " << "Pergi ke goa yang ada didekat desa itu. Benar saja, ada " << "[" + musuh.nama + "] " << "didalam goa itu." << endl;
            cout << "Kau masuk dengan membawa senjata mu sambil mengendap-endap, namun " << "[" + musuh.nama + "] " << "itu menyadari mu. " << "[" + musuh.nama + "] " <<  " itu mulai mendekat dan menyerang...";
            spasi(2);
            getline(cin, blank);
            cout << "Musuh menyerang duluan" << endl;
            do {
                infoMusuh();
                hpTerbaruPemain();
                infoPemain();
                if (player.hp == 0) {
                    spasi(24);
                    cout << "Kau telah kalah! " << "[" + musuh.nama + "] " << " mengalahkanmu.";
                    spasi(2);
                    cout << "Petualang itu tewas dan jasadnya dimakan oleh " << "[" + musuh.nama + "]";
                    spasi(2);
                    break;
                }
                cout << "Giliran mu untuk menyerang" << endl;
                if (player.jobPilih == 1) {
                    seranganPlayerPenyihir();
                } else if (player.jobPilih == 2) {
                    seranganPlayerKsatria();
                }
                if (musuh.hp == 0) {
                    spasi(24);
                    cout << "=======================================" << endl;
                    cout << "Selamat! Kau telah mengalahkan " << "[" + musuh.nama + "]" << "." << endl;
                    cout << "=======================================";
                    spasi(3);
                    cout << "\n" << player.nickname << " pergi memberitahu (Penduduk Desa) tadi bahwa monster " << "[" + musuh.nama + "] " << "telah berhasil dikalahkan.";
                    spasi(2);
                    cout << "(Penduduk Desa) " <<  quest1[4] << " Bolehkah aku mengetahui namamu?" << endl;
                    do {
                        cout << "Response>> (Ya/Tidak) >> ";
                        getline(cin, response);
                    } while (response.empty());
                    spasi(1);
                    if (response == "Tidak" || response == "tidak" || response == "TIDAK") {
                        cout << "Mohon maaf, tidak sekarang." << endl;
                        } else {
                        cout << "Namaku " << player.first_name << ". Biasa dipanggil " << player.nickname << ". Senang bisa membantumu";
                        spasi(1);
                        cout << "(Penduduk Desa) " << quest1[4] << " " << quest1[5] << "(" + player.nickname + ")." << endl;
                        }
                    end();
                }
            } while (musuh.hp>0 && player.hp>0);
        }
    return 0;
}
