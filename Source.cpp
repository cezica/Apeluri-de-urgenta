#include<iostream>
#include<SFML/Network.hpp>
using namespace std;

int main()
{
    sf::IpAddress ip;
    sf::TcpSocket socket;
    size_t received;
    char buffer[2000];
    string data;


    ip = sf::IpAddress::getLocalAddress();
    
    socket.connect(ip, 2000);
    
    string text = "Conectat la Server";
    cout << text << endl;
    while (true)
    { 
        //0. logare
        //text = "0$elena123$parolaelena$";
        //text = "0$ana_otilia$parola@n@$";
        
        //1. inregistrare
        //text = "1$elena123$parolaelena$Tepes$Elena$elena_ruxandra@yahoo.com$0752551224$" ;
        text = "1$ana_otilia$parola@n@$Tepes$Ana$ana_tepes@gmail.com$0748778331$";

        //2. istoric apel -> administrator
        //text = "2$elena123$dispecer1$10.05.2022 18:22:08$10.05.2022 18:23:00$fisier1$";
        //text = "2$elena123$dispecer2$10.05.2022 14:02:08$10.05.2022 14:07:01$fisier2$";
        //text = "2$elena123$dispecer1$11.05.2022 5:12:08$11.05.2022 5:17:01$fisier3$";
        //text = "2$ana_otilia$dispecer1$10.05.2022 7:12:22$10.05.2022 7:35:10$fisier4$";

        //3. istoric apel -> un utilizator
        //text = "3$elena123$";
        //text = "3$ana_otilia$";
        //text = "3$ana$"; //daca nu este corect mesajul

        //4. istoric dispecer fara detalii
        //text = "4$dispecer1$";

        //5. adaug detalii si mut din asteptare in istoric
        //text = "5$dispecer1$1$fara detalii$";

        //6.istoric apeluri dispecer -> username_client$data+timp$detalii$fisier_audio$
       // text = "6$dispecer1$";
        
        //7.afiseaza toti utilizatorii pt dispecer -> username$nume$prenume$email$telefon$*
       // text = "7$";

        //8. intoarce istoric apeluri admin
        //text = "8$";

        //9. stergere dispecer
        //text = "9$dispecer1$";

        //10. adaugare dispecer
        //text = "10$dispecer3$parola$blablablatralala_email@blabla.com$nume3$prennume3$Pompieri$0000000003$";

        //11.inregistrari utilizatori in asteptare
        //text = "11$";

        //12.
       text = "12$maria$";

        //13. respinge inregistrare
       //text = "13$maria$";

        //14. sterge utilizatorul
        //text = "14$user1$";

        //15.
        //text = "";

        socket.send(text.c_str(), text.length() + 1);

        socket.receive(buffer, sizeof(buffer), received);
        if (received > 0)
            cout << buffer << endl;
        if (buffer == "v")
            cout << "S-a efectuat cu succes" << endl;
    }
}