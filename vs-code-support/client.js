const { ExtensionContext, languages, workspace } = require('vscode');
const { LanguageClient, ServerOptions, TransportKind } = require('vscode-languageclient/node');
const path = require('path');

let client;

function activate(context) {
    // Binary path - assumed to be built in the root
    let serverModule = context.asAbsolutePath(path.join('..', 'fle-lsp'));

    let serverOptions = {
        run: { command: serverModule, transport: TransportKind.stdio },
        debug: { command: serverModule, transport: TransportKind.stdio }
    };

    let clientOptions = {
        documentSelector: [{ scheme: 'file', language: 'fastlogentry' }],
        synchronize: {
            fileEvents: workspace.createFileSystemWatcher('**/*.fle')
        }
    };

    client = new LanguageClient(
        'fleLSP',
        'Fast Log Entry LSP',
        serverOptions,
        clientOptions
    );

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
