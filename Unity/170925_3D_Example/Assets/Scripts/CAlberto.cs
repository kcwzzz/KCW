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
            mpScene.OnClickBtnGoScenePlayGame();
            Debug.Log("Colision");
        }
    }

}
