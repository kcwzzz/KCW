using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CUnit : MonoBehaviour {

    protected CScenePlayGAme mpScene = null;
    protected bool mIsAlive = false;
    protected Animator mpAnimator = null;

    public enum STATE
    {
        IDLE = 0,
        ATTACK = 1,
        DEAD = 2

    };

    public STATE mState = STATE.IDLE;

    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update ()
    {
		
	}

    virtual public void CreateAni()
    {
        mIsAlive = true;
        mpAnimator = GetComponentInChildren<Animator>();
    }

    public void SetScene(CScenePlayGAme tpScene)
    {
        mpScene = tpScene;

    }

    virtual public void UpdateAni()
    {

    }


    public bool IsAlive()
    {
        return mIsAlive;
    }

    public void SetAlive(bool tisAlive)
    {
        mIsAlive = tisAlive;
    }

    public bool IsShow()
    {
        return this.gameObject.activeInHierarchy;
    }

    public void Show()
    {
        this.gameObject.SetActive(true);
    }

    public void Hide()
    {
        this.gameObject.SetActive(false);
    }


}