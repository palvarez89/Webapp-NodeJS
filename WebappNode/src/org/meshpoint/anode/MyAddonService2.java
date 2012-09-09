package org.meshpoint.anode;

/*******************************************************************************
 *
 *    Copyright (c) Baina Info Tech Co. Ltd
 *
 *    HelloWorld
 *
 *    MyAddonService
 *    TODO File description or class description.
 *
 *    @author: dhu
 *    @since:  2012-5-21
 *    @version: 1.0
 *
 ******************************************************************************/

import java.io.File;

import org.meshpoint.anode.R;
import org.meshpoint.anode.Runtime.IllegalStateException;
import org.meshpoint.anode.Runtime.InitialisationException;
import org.meshpoint.anode.Runtime.NodeException;
import org.meshpoint.anode.Runtime.StateListener;

import com.dolphin.browser.addons.AddonService;
import com.dolphin.browser.addons.AlertDialogBuilder;
import com.dolphin.browser.addons.Browser;
import com.dolphin.browser.addons.OnClickListener;

import android.app.IntentService;
import android.content.Context;
import android.content.ContextWrapper;
import android.content.Intent;
import android.graphics.BitmapFactory;
import android.os.Handler;
import android.os.Vibrator;
import android.text.style.SuperscriptSpan;
import android.util.Log;
import android.widget.Toast;

/**
 * MyAddonService of HelloWorld.
 * 
 * @author dhu
 * 
 */

public class MyAddonService2 extends AddonService implements StateListener {
	private Isolate isolate;
	private String instance;
	Context ctx;
	private long uiThread;
	private Handler viewHandler = new Handler();
	boolean configured = false;

	@Override
	protected void onBrowserConnected(Browser browser) {

		if (!configured) {
			Log.w("ANODEEE", "constructor");
			isolate = null;
			instance = null;
			ctx = getApplicationContext();
			configured = true;
		}

		Log.w("ANODEEE", "Lanzando server");

		initRuntime(null);

		char sep = File.separatorChar;
		String packageName = ctx.getPackageName();
		String serverPath = sep + "data" + sep + "data" + sep + packageName
				+ sep + "server";
		String args = serverPath + sep + "main.js";

		// --------------

		/* otherwise, start service */
		// Intent intent = new Intent(getBaseContext(),AnodeService.class);
		// intent.setClassName(ctx, AnodeService.class.getName());
		// ctx.startService(intent);

		// --------

		if (instance == null) {

			try {
				isolate = Runtime.createIsolate();
				isolate.addStateListener(this);
				this.instance = AnodeService.addInstance(instance, isolate);
				isolate.start(args.split("\\s"));
			} catch (IllegalStateException e) {
				Log.v(TAG,
						"isolate start: exception: " + e + "; cause: "
								+ e.getCause());
			} catch (NodeException e) {
				Log.v(TAG, "isolate start: exception: " + e);
			}

		} else {

			Log.w("ANODEEE", "Servidor ya lanzado");
		}

		// _--
		try {
			// Show add-on bar action
			browser.addonBarAction.setIcon(BitmapFactory.decodeResource(
					getResources(), R.drawable.ic_launcher));
			browser.addonBarAction.setTitle("Anode");
			browser.addonBarAction.setOnClickListener(new OnClickListener() {

				public void onClick(Browser browser) {
					showHelloWorldDialog(browser);

				}
			});
			browser.addonBarAction.show();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	public void initRuntime(String[] opts) {
		try {
			Runtime.initRuntime(ctx, opts);
		} catch (InitialisationException e) {
			Log.v(TAG,
					"initRuntime: exception: " + e + "; cause: " + e.getCause());
		}
	}

	private void showHelloWorldDialog(Browser browser) {
		// show dialog
		AlertDialogBuilder builder = new AlertDialogBuilder();
		builder.setTitle("Title");
		builder.setMessage("Hello World MAN!!");
		builder.setPositiveButton("Close",
				obtainOnClickListenerMessage(new OnClickListener() {

					public void onClick(Browser browser) {
						Toast.makeText(MyAddonService2.this, "Dialog closed",
								Toast.LENGTH_SHORT).show();
					}
				}));
		try {
			browser.window.showDialog(builder);
			Vibrator v = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);
			int dot = 200; // Length of a Morse Code "dot" in milliseconds
			int dash = 500; // Length of a Morse Code "dash" in milliseconds
			int short_gap = 200; // Length of Gap Between dots/dashes
			int medium_gap = 500; // Length of Gap Between Letters
			int long_gap = 1000; // Length of Gap Between Words
			long[] pattern = { 0, // Start immediately
					dot, short_gap, dot, short_gap, dot, // s
					medium_gap, dash, short_gap, dash, short_gap, dash, // o
					medium_gap, dot, short_gap, dot, short_gap, dot, // s
					long_gap };
			v.vibrate(pattern, -1);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@Override
	protected void onBrowserDisconnected(Browser browser) {

		try {
			isolate.stop();
		} catch (IllegalStateException e) {
			Log.v(TAG, "AnodeReceiver.onReceive::stop: exception: " + e
					+ "; cause: " + e.getCause());
		} catch (NodeException e) {
			Log.v(TAG, "AnodeReceiver.onReceive::stop: exception: " + e
					+ "; cause: " + e.getCause());
		}
	}

	@Override
	public void stateChanged(final int state) {
		if (Thread.currentThread().getId() == uiThread) {
			__stateChanged(state);
		} else {
			viewHandler.post(new Runnable() {
				public void run() {
					__stateChanged(state);
				}
			});
		}
	}

	private void __stateChanged(final int state) {
		// stateText.setText(getStateString(state));
		// startButton.setEnabled(state == Runtime.STATE_CREATED);
		// stopButton.setEnabled(state == Runtime.STATE_STARTED);
		/* exit the activity if the runtime has exited */

		if (state == Runtime.STATE_STOPPED) {

			initRuntime(null);

			char sep = File.separatorChar;
			String packageName = ctx.getPackageName();
			String serverPath = sep + "data" + sep + "data" + sep + packageName
					+ sep + "server";
			String args = serverPath + sep + "main.js";

			Log.w("ANODEEE", "Relanzando servidor");
//			try {
//				isolate = Runtime.createIsolate();
//				isolate.addStateListener(this);
//				this.instance = AnodeService.addInstance(instance, isolate);
//				isolate.start(args.split("\\s"));
//			} catch (IllegalStateException e) {
//				Log.v(TAG,
//						"isolate start: exception: " + e + "; cause: "
//								+ e.getCause());
//			} catch (NodeException e) {
//				Log.v(TAG, "isolate start: exception: " + e);
//			}

		}
	}

}
