/**
 * \file ItemVisitor.h
 *
 * \ Team Plessie
 *
 * Item visitor base class.
 */

#pragma once

 // Forward references to all Item types
class CMoney;
class CGnome;
class CKey;
class CPlatform;
class CTuitionUp;
class CVillain;
class CWall;
class CDoor;
class CAdr;
class CBackground;


class CItemVisitor
{
public:
    virtual ~CItemVisitor() {}

    /** Visit a CMoney object
     * \param money Money we are visiting */
    virtual void VisitMoney(CMoney* money) {}

    /** Visit a CGnome object
     * \param gnome Gnome we are visiting */
    virtual void VisitGnome(CGnome* gnome) {}

    /** Visit a CKey object
     * \param key Key we are visiting */
    virtual void VisitKey(CKey* key) {}

    /** Visit a CPlatform object
     * \param platform Platform we are visiting */
    virtual void VisitPlatform(CPlatform* platform) {}

    /** Visit a CTuitonUp object
     * \param tuitonup TuitionUp we are visiting */
    virtual void VisitTuitionUp(CTuitionUp* tuitionup) {}

    /** Visit a CVillain object
     * \param villain Villain we are visiting */
    virtual void VisitVillain(CVillain* villain) {}

    /** Visit a CWall object
     * \param wall Wall we are visiting */
    virtual void VisitWall(CWall* wall) {}

    /** Visit a CDoor object
     * \param door Door we are visiting */
    virtual void VisitDoor(CDoor* door) {}

    /** Visit a CAdr object
     * \param adr Adr we are visiting */
    virtual void VisitAdr(CAdr* adr) {}

    /** Visit a CAdr object
     * \param adr Adr we are visiting */
    virtual void VisitBackground(CBackground* background) {}
};

