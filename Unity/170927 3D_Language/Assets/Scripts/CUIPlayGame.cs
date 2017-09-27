using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;


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

    public void OnClickBtnCoSceneTitle()
    {
        SceneManager.LoadScene("CSceneTitle");       
        //SceneManager.LoadScene("CScenePlayGameUI", LoadSceneMode.Additive);
        //SceneManager.LoadScene("CSceneGrid_1", LoadSceneMode.Additive);
    }

}
