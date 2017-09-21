using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CAlberto : CUnit
{
    public enum STATE
    {
        IDLE = 0,
        ATTACK = 1,
        DEAD = 2

    };

    STATE mState = STATE.IDLE;

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

    public void SetState(STATE tState)
    {
        mState = tState;
    }

    public STATE GetState()
    {
        return mState;
    }

    public void DoState()
    {
        switch (mState)
        {
            case STATE.IDLE:
                {
                    mpAnimator.SetTrigger("mTrigAniIdle");
                }
                break;

            case STATE.ATTACK:
                {
                    mpAnimator.SetTrigger("mTrigAniAttack");
                }
                break;

            case STATE.DEAD:
                {
                    mpAnimator.SetTrigger("mTrigAniDead");
                }
                break;
        }
    }

    void OnTriggerEnter2D(Collider2D tCollider)
    {
        if (STATE.DEAD != mState)
        {
            if (true == tCollider.CompareTag("tagEnemy"))
            {
                Debug.Log("trigging");

                SetState(STATE.DEAD);
                DoState();

                mpScene.mpDxGameOver.show();                
            }
        }
    }
}
