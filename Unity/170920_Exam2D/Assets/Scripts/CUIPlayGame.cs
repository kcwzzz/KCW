using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CUIPlayGame : MonoBehaviour {

    protected CScenePlayGAme mpScene = null;

    float tDirX = 0.0f;

    public void SetScene(CScenePlayGAme tpScene)
    {
        mpScene = tpScene;
    }

	// Use this for initialization
	void Start ()
    {
		
	}
	
	// Update is called once per frame
	void Update ()
    {
		
	}

    public void OnClickBtnAttackLt()
    {
        tDirX = -1.0f;
        Debug.Log("CUIPlayGame.OneClickBtnAttackLeft");
        mpScene.AlbertoDoAttack(tDirX);

    }

    public void OnClickBtnAttackRt()
    {
        tDirX = 1.0f;
        Debug.Log("CUIPlayGame.OneClickBtnAttackRight");
        mpScene.AlbertoDoAttack(tDirX);        
    }
}
