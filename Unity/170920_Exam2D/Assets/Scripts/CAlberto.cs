using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CAlberto : CUnit
{


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
                    
                    DoAttack();
                }
                break;

            case STATE.DEAD:
                {
                    //mpAnimator.SetTrigger("mTrigAniDead");
                    Destroy(this.gameObject);
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

                mpScene.mpDxGameOver.Show();
            }
        }
    }

    public void DoAttack()
    {        
        mpAnimator.SetTrigger("mTrigAttack");
        CBullet tBullet =  Instantiate<CBullet>(mpScene.PFBullet, this.transform.position,
                             Quaternion.identity);

        float tAlbertoDirX =  this.transform.localScale.x;

        tBullet.SetBuletDirX(tAlbertoDirX);

        if (STATE.IDLE == mState)
        {
            mState = STATE.DEAD;
            mpAnimator.SetTrigger("mTrigAttack");
        }
    }
}
