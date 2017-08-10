//
//  CContactListener.cpp
//  BuildAndStudio_2
//
//  Created by pokpoongryu on 2016. 8. 20..
//
//

#include "CContactListener.h"

//#include "CSceneBox2d_0.h"


CContactListener::CContactListener()
{
    
}
CContactListener::~CContactListener()
{
    
}
//두 바디가 처음 접촉했을 때 호출된다.
void CContactListener::BeginContact( b2Contact *contact)
{
    log("BeginContact");
    
    //충돌된 Physical Body들을 자료구조에 담아놓는다.
    SContacts tSContacts;
    tSContacts.fixtureA = contact->GetFixtureA();
    tSContacts.fixtureB = contact->GetFixtureB();
    
    mSContacts.push_back(tSContacts);
    
}
////두 바디가 떨어졌을 때 호출된다.
void CContactListener::EndContact( b2Contact *contact )
{
    
    log("EndContact");
    
    //Physical Body들의 충돌이 끝났다면 충돌된 바디 자료구조에서 삭제한다.
    SContacts myContact = { contact->GetFixtureA(), contact->GetFixtureB() };
    std::vector<SContacts>::iterator pos;
    pos = std::find(mSContacts.begin(), mSContacts.end(), myContact);
    
    if (pos != mSContacts.end())
    {
        mSContacts.erase(pos);
    }

}
//두 바디가 접촉하고 있는 동안 호출된다.
void CContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
    //log("PreSolve");
}
//두 바디가 접촉했으며, 충돌을 이미 처리했을때? 호출된다.
void CContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
    /*
    log("PostContact");
    
    
    b2Fixture *tpFixA = contact->GetFixtureA();
    b2Fixture *tpFixB = contact->GetFixtureB();
    
    b2Body *tpBodyA = tpFixA->GetBody();
    b2Body *tpBodyB = tpFixB->GetBody();
    
    if( tpBodyA->GetType() == b2_dynamicBody || tpBodyB->GetType() == b2_dynamicBody )
    {
        log("Contact:impulse: %f", impulse->normalImpulses[0] );
        log("Contact:impulse: %f", impulse->normalImpulses[1] );
    }
     */
}