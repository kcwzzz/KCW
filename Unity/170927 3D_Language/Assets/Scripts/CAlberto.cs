using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CAlberto : CRyuUnit
{

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    public void DoState()
    {
        switch(mState)
        {
            case STATE.IDLE:
                {

                }
                break;

            case STATE.Move:
                {

                }
                break;        
        }
    }

    public void OnTriggerEnter(Collider tCollider)
    {

        if(true == tCollider.CompareTag("tagLamp"))
        {
            CRyuSoundMgr.GetInst().Play(4);
            mpScene.OnClickBtnGoScenePlayGame();
            Debug.Log("Colision");
        }
    }

    override public void DoMove()
    {
        base.DoMove();
        CRyuSoundMgr.GetInst().Play(3);
    }

    override public void DoRatote()
    {
        base.DoRatote();
        CRyuSoundMgr.GetInst().Play(3);
    }


}
