using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CAlberto : CRyuUnit
{
    Vector3 mDir = Vector3.zero;
    public CBullet PFBulletSphere = null;
    List<CBullet> mBulletList = null;
    int mBulletCount = 0;

    // Use this for initialization
    void Start () {
        mBulletList = new List<CBullet>();

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
        mDir.y += 90.0f;
        CRyuSoundMgr.GetInst().Play(3);
    }


    override public void DoFire()
    {
        mBulletCount = mBulletList.Count;
        CBullet tpBullet = null;

        tpBullet=Instantiate<CBullet>(CRyuGameDataMgr.GetInst().PFBulletSphere,
            Vector3.zero,Quaternion.identity);

        Vector3 tPosition = new Vector3(this.transform.position.x,
    this.transform.position.y + 0.25f, this.transform.position.z);

        tpBullet.transform.position = tPosition;
        
        tpBullet.transform.Rotate(mDir);

        mBulletList.Add(tpBullet);
        mBulletList[mBulletCount].CreateAni();
    }

}
