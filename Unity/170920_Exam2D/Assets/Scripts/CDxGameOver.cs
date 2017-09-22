using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CDxGameOver : MonoBehaviour
{
    private CScenePlayGAme mpScene = null;

    Animator mpAnimator = null;

    // Use this for initialization
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {

    }
    public void CreateRyu()
    {
        mpAnimator = GetComponentInChildren < Animator>();
    }

    public void SetScene(CScenePlayGAme tpScene)
    {
        mpScene = tpScene;
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

    public void OnClickBtnRetry()
    {
        this.Hide();
        
    }
}
