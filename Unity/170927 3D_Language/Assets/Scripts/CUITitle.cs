using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

using UnityEngine.UI;

public class CUITitle : MonoBehaviour
{

    public Text mpTxtTitle = null;
    public Text mpTxtBtnGoScenePlayGame = null;
    public Text mpTxtBtnGoSceneConfig = null;
    public Text mpTxtInfo = null;

    // Use this for initialization
    void Start()
    {
        BuildUIWithLangType();
    }

    // Update is called once per frame
    void Update()
    {

    }

    public void BuildUIWithLangType()
    {
        mpTxtTitle.text = CRyuGameDataMgr.GetInst().mLangTextList[0];
        mpTxtBtnGoScenePlayGame.text = CRyuGameDataMgr.GetInst().mLangTextList[1];
        mpTxtBtnGoSceneConfig.text = CRyuGameDataMgr.GetInst().mLangTextList[2];
        mpTxtInfo.text = CRyuGameDataMgr.GetInst().mLangTextList[3];
    }

    public void OnClickBtnGoScenePlayGame()
    {
        CRyuSoundMgr.GetInst().Play(0);
        SceneManager.LoadScene("CScenePlayGame");
        SceneManager.LoadScene("CSceneGrid_0", LoadSceneMode.Additive);
        SceneManager.LoadScene("CScenePlayGameUI", LoadSceneMode.Additive);

    }

    public void OnClickBtnGoSceneConfig()
    {
        CRyuSoundMgr.GetInst().Stop(0);
        SceneManager.LoadScene("CSceneConfig");
    }
}
