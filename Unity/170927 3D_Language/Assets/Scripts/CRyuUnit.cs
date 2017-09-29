using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CRyuUnit : MonoBehaviour
{
    protected Animator mpAnimator = null;
    protected CScenePlayGame mpScene = null;
    
    public enum STATE
    {
        IDLE = 0,
        Move = 1
    };

    public STATE mState = STATE.IDLE;

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

    virtual public void SetState(STATE tState)
    {
        mState = tState;
    }

    virtual public STATE GetState()
    {
        return mState;
    }

    virtual public Animator GetAni()
    {
        return mpAnimator;
    }

    virtual public void CreateAni()
    {
        mpAnimator = GetComponentInChildren<Animator>();
    }

    virtual public void SetScene(CScenePlayGame tpScene)
    {
        mpScene = tpScene;
    }


    virtual public void DoMove()
    {
        this.transform.Translate(Vector3.forward, Space.Self);
        //forward z축의  +방향으로, 1Unit씩 Self = 로컬 좌표계(알베르토의 좌표) 
    }

    virtual public void DoRatote()
    {
        this.transform.Rotate(Vector3.up, 90.0f, Space.Self);
        
    }

    virtual public void DoFire()
    {
        
    }
}
