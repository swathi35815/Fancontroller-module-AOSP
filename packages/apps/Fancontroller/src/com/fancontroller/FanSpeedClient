import android.os.IBinder;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.util.Log;

/**
 * Client class for interacting with the FanSpeedControlService.
 * Provides methods to control the fan speed.
 */
public class FanSpeedClient {
    private static final String TAG = "FanSpeedClient";
    private static final String IFANSPEEDCONTROL_SERVICE="com.example.fancontrollerapp.IFanSpeedControlService/default" (Location of the service class);
    private IFanSpeedControlService fanSpeedControlService;

    public FanSpeedClient() {
        // Get the binder from the ServiceManager
        IBinder binder = ServiceManager.getService(IFANSPEEDCONTROL_SERVICE);
        if (binder == null) {
            Log.e(TAG, "Getting " + IFANSPEEDCONTROL_SERVICE + " service daemon binder failed!");
        } else {
            fanSpeedControlService = IFanSpeedControlService.Stub.asInterface(binder);
            if (fanSpeedControlService == null) {
                Log.e(TAG, "Getting IFanSpeedControlService AIDL daemon interface failed!");
            } else {
                Log.d(TAG, "IFanSpeedControlService AIDL daemon interface is binded!");
            }
        }
    }

    public void increaseFanSpeed() {
        try {
            if (fanSpeedControlService != null) {
                fanSpeedControlService.increaseFanSpeed();
            }
        } catch (RemoteException e) {
            Log.e(TAG, "RemoteException", e);
        }
    }

    public void decreaseFanSpeed() {
        try {
            if (fanSpeedControlService != null) {
                fanSpeedControlService.decreaseFanSpeed();
            }
        } catch (RemoteException e) {
            Log.e(TAG, "RemoteException", e);
        }
    }

    public void turnFanOn() {
        try {
            if (fanSpeedControlService != null) {
                fanSpeedControlService.turnFanOn();
            }
        } catch (RemoteException e) {
            Log.e(TAG, "RemoteException", e);
        }
    }

    public void turnFanOff() {
        try {
            if (fanSpeedControlService != null) {
                fanSpeedControlService.turnFanOff();
            }
        } catch (RemoteException e) {
            Log.e(TAG, "RemoteException", e);
        }
    }

    public int getFanSpeed() {
        try {
            if (fanSpeedControlService != null) {
                return fanSpeedControlService.getFanSpeed();
            }
        } catch (RemoteException e) {
            Log.e(TAG, "RemoteException", e);
        }
        return 0;
    }

    public boolean isFanOn() {
        try {
            if (fanSpeedControlService != null) {
                return fanSpeedControlService.isFanOn();
            }
        } catch (RemoteException e) {
            Log.e(TAG, "RemoteException", e);
        }
        return false;
    }
}