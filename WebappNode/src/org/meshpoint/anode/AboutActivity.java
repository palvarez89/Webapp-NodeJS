package org.meshpoint.anode;
/*******************************************************************************
 *
 *    Copyright (c) Baina Info Tech Co. Ltd
 *
 *    SampleAddon
 *
 *    AboutActivity
 *    TODO File description or class description.
 *
 *    @author: dhu
 *    @since:  2012-5-24
 *    @version: 1.0
 *
 ******************************************************************************/


import org.meshpoint.anode.AnodeActivity;

import android.content.Intent;

/**
 * AboutActivity of SampleAddon.
 * @author dhu
 *
 */
public class AboutActivity extends com.dolphin.browser.addons.AboutActivity {

    @Override
    protected void onStartCustomAboutActivity() {
        startActivity(new Intent(this, AnodeActivity.class));
    }

}
