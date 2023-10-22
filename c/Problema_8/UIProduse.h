///modul ce contine tot ce tine de interfata utilizator pentru produse

#ifndef _UIPRODUSE_H
#define _UIPRODUSE_H
#include "ServiciuProduse.h"

typedef struct {
	ServiciuProduse* serv;
}UIProduse;

/*creaza o interfata utilizator produse
Pre:->serv este pointer la un ServiciuProduse
Post:->functia returneaza un pointer la un UIPRODUSE
!!!UIPRODUSE TREBUIE DISTRUS DUPA CU distruge_uiproduse*/
UIProduse* creaza_uiproduse(ServiciuProduse* serv);

/*distruge un uiproduse
Pre:->uip este un pointer la un UIProduse
Post:->entitatea UIProdsue este distrusa si memoria eliberata*/
void distruge_uiproduse(UIProduse* uip);

/*ruleaza interfata uip
Pre:->uip este pointer la un UIProduse
Post:->aplicatai este rulata*/
void ruleaza_uip(UIProduse* uip);

#endif