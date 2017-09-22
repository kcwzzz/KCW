using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CEnemy : CUnit
{

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    virtual public void DoState()
    {
        switch (mState)
        {
            case STATE.IDLE:
                {
                    mpAnimator.SetTrigger("mTrigAniIdle");
                }
                break;

            case STATE.DEAD:
                {
                    mpAnimator.SetTrigger("mTrigAniDead");
                    Destroy(this.gameObject);
                }
                break;
        }
    }
}
