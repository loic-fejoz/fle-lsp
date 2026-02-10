const os = require('os');
const path = require('path');
const vscode = require('vscode');
const { LanguageClient, TransportKind } = require('vscode-languageclient/node');

let client;

function activate(context) {
    // Detect binary name based on platform
    const platform = os.platform();
    let executableName = 'fle-lsp';

    if (platform === 'win32') {
        executableName += '.exe';
    }

    // Binary path - look into 'bin' subdirectory of the extension
    let serverModule = context.asAbsolutePath(path.join('bin', executableName));

    // Fallback for development if 'bin' doesn't exist (look in root or parent)
    // This is useful for F5 development in the repo itself
    if (!require('fs').existsSync(serverModule)) {
        serverModule = context.asAbsolutePath(path.join('..', executableName));
    }

    let serverOptions = {
        run: { command: serverModule, transport: TransportKind.stdio },
        debug: { command: serverModule, transport: TransportKind.stdio }
    };

    let clientOptions = {
        documentSelector: [{ scheme: 'file', language: 'fastlogentry' }],
        synchronize: {
            fileEvents: vscode.workspace.createFileSystemWatcher('**/*.fle')
        }
    };

    client = new LanguageClient(
        'fleLSP',
        'Fast Log Entry LSP',
        serverOptions,
        clientOptions
    );

    context.subscriptions.push(vscode.commands.registerCommand('fle.convertGeoJsonUI', async () => {
        const editor = vscode.window.activeTextEditor;
        if (!editor) {
            return;
        }
        await vscode.commands.executeCommand('fle.convertGeoJson', editor.document.uri.toString());
    }));

    client.start();
}

function deactivate() {
    if (!client) {
        return undefined;
    }
    return client.stop();
}

module.exports = {
    activate,
    deactivate
};
