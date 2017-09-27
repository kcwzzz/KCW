using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class CUIConfig : MonoBehaviour
{

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

    public void OnClickBtnGoSceneTitle()
    {
        SceneManager.LoadScene("CSceneTitle");
    }

    public void OnClickBtnSelectEn()
    {
        CRyuGameDataMgr.GetInst().BuildLangType(1);

    }
    
    public void OnClickBtnSelectKo()
    {
        CRyuGameDataMgr.GetInst().BuildLangType(0);
    }
}
