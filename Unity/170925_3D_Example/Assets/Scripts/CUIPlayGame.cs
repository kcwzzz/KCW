using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CUIPlayGame : MonoBehaviour
{
    protected CScenePlayGame mpScene = null;
    protected Animator mpAnimator = null;

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }
    



    public void OnClickBtnMove()
    {
        mpScene.GetAlberto().GetAni().SetTrigger("mTrigMove");
        mpScene.GetAlberto().DoMove();
    }

    public void OnClickBtnRotate()
    {
        mpScene.GetAlberto().GetAni().SetTrigger("mTrigRotate");
        mpScene.GetAlberto().DoRatote();
    }

    public void SetScene(CScenePlayGame tpScene)
    {
        mpScene = tpScene;
    }

}
