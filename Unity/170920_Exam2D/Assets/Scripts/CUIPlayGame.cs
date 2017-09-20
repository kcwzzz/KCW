using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CUIPlayGame : MonoBehaviour {

    protected CScenePlayGAme mpScene = null;

    public void SetScene(CScenePlayGAme tpScene)
    {
        mpScene = tpScene;
    }
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    public void OnClickBtnAttack()
    {
        Debug.Log("CUIPlayGame.OneClickBtnAttack");
        mpScene.mpAlberto.DoAttack();
    }
}
